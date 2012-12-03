/**
 * Topic:   Okruh 4: SHO Vyrobni linka
 *          Vyroba reklam BOSE
 * Authors: Jan Pacner (xpacne00@stud.fit.vutbr.cz)
 *          Lukas Frencl (xfrenc00@stud.fit.vutbr.cz)
 * Date:    2012-12-01 10:56:23 CET
 */

#include <simlib.h>
#include <iostream>
//#include <fstream>
//using namespace std;

class Order: public Process
{
  protected:
    const int count;  /* advertisments count */
    void Behavior();
  public:
    unsigned int id;
    //Order(int _count, Priority_t _prior) :
    //  Priority(_prior), count(_count)
    Order(Priority_t, int);
    static void Alloc(Priority_t, int);
};

/* the mean order volume */
const unsigned int ORDINARY_ORDER = 20;
/* letters needed for one advertisement */
const unsigned int ADVERT_LETTERS = 4;
/* volume (in letters) of one crate */
const unsigned int CRATE_VOL_MAX = 8;
const unsigned int PLEXI_SHEET_PARTS = 55;
const unsigned int COMPLETION_EMPLOEES = 2;
const unsigned int STAKE_CAPACITY = 40;
unsigned int OrderID = 0;
Histogram Table0("Muj nazev", 0, 0.1, 20); //FIXME

int MAX(double x, double y) { return (x > y) ? x : y; }

//FIXME prevzato z prikladu centrala.cc
/* ptr to static method */
typedef void (*AllocPtr_t)(Entity::Priority_t, int);
//typedef void (*AllocPtr_t)(simlib3::Entity::Priority_t, int);

class Generator : public Event
{
  protected:
    AllocPtr_t alloc;

    void Behavior()
    {
      alloc(Exponential(4), MAX(Exponential(ORDINARY_ORDER),
            CRATE_VOL_MAX / ADVERT_LETTERS));
      /* meantime between new requests */
      Activate(Time + Exponential(4 * 60));
    }

  public:
    Generator(AllocPtr_t _ptr) :
      alloc(_ptr)
    {
      Activate();
    }
};

class GrinderC: public Facility
{
  public:
    /* planned failure */
    unsigned int fail_after;
    /* current count of grinded letters */
    unsigned int cur_n;

    GrinderC(const char* _s) : Facility(_s)
    {
      scheduleFailure();
    }

    void Seize(Entity *e, ServicePriority_t sp=DEFAULT_PRIORITY)
    {
      Facility::Seize(e, sp);
      cur_n += CRATE_VOL_MAX;
    }

    void scheduleFailure()
    {
      fail_after = Uniform(50, 80);
      cur_n = 0;
    }

    bool failed()
    {
      return cur_n >= fail_after;
    }
};

Facility Plotter("Plexiglass plotter");
GrinderC Grinder("Plexiglass grinder");
Facility Paintshop("Plexiglass letters paintshop");
Facility Desks[COMPLETION_EMPLOEES];

/* prepravka /bedna/ */
class Crate: public Process
{
  protected:
    /* parent */
    Order *parent;
    bool start_batch;

    void Behavior()
    {
      if (Plotter.Busy())
      {
        /* -1 because one crate already seized the Plotter */
        if (Plotter.QueueLen() >= PLEXI_SHEET_PARTS / CRATE_VOL_MAX +
            ((PLEXI_SHEET_PARTS % CRATE_VOL_MAX == 0) ? 0 : 1) -1)
        {
          /* tell the crate within the plotter, that the batch is
             complete and plot can start */
          //FIXME klidne tedka muze byt provadeno rezani na plotteru (takze
          //  je Busy, ale tim padem je ten proces uz aktivovany a ten
          //  aktualni by se mel naplanovat s casem rezani 0)
          Plotter.in->Activate();
          //plotter_batch_start->BatchCanStart();

          /* become the first part of new batch */
          Seize(Plotter);
          //FIXME WaitUntil(start_batch);
          /* cut the plexi sheet */
          Passivate();
          Wait(Time + 95 + Uniform(50, 70));
          Release(Plotter);
        }
        else
        {
          /* enter the plotter queue and become a member of future batch */
          //FIXME fail!
std::cerr << "[" << parent->id << "] short SEIZE " << Time << "\n";//FIXME
          Seize(Plotter);
          //Wait(0);
          Release(Plotter);
std::cerr << "[" << parent->id << "] short RELEA " << Time << "\n";//FIXME
        }
      }
      else
      {
        Seize(Plotter);
        /* cut the plexi sheet */
        Passivate();
        Wait(Time + 95 + Uniform(50, 70));
        Release(Plotter);
      }

      if (Grinder.failed())
      {
        Wait(Time + Uniform(20, 30));
        if (Grinder.failed()) Grinder.scheduleFailure();
      }

      Seize(Grinder);
      Wait(Time + CRATE_VOL_MAX * Uniform(10, 15));
      Release(Grinder);
std::cerr << "[" << parent->id << "] after grinder\n"; //FIXME
      /* 9 paint layers */
      for (int i = 0; i < 9; ++i)
      {
std::cerr << "[" << parent->id << "] painting layer " << i << "\n"; //FIXME
        if (Paintshop.Busy())
        {
          if (Paintshop.QueueLen() >= STAKE_CAPACITY / CRATE_VOL_MAX +
              ((STAKE_CAPACITY % CRATE_VOL_MAX == 0) ? 0 : 1) -1)
          {
            Paintshop.in->Activate();
            // FIXME paintshop_batch_start->BatchCanStart();

            Seize(Paintshop);
            Passivate();
            Wait(Time + Uniform(25, 35));  /* painting */
            Release(Paintshop);
          }
          else
          {
            //FIXME fail?
            Seize(Plotter);
            //Wait(0);
            Release(Plotter);
          }
        }
        else
        {
          Seize(Paintshop);
          Passivate();
          //FIXME chybovost lakovani!
          Wait(Time + Uniform(25, 35));  /* painting */
          Release(Paintshop);
        }

        /* next layer first after 60 minutes */
        Wait(Time +60);
      }
std::cerr << "HOWK33\n"; //FIXME

      /* wait for final paint dry; -60 because we already waited that long */
      //FIXME zanedbat vzhledem k dlouhe cekaci dobe a malemu casu simulace?
      //Wait(Time + Uniform(20, 24) * 60 -60);

      /* get some free desk */
      int x = int(COMPLETION_EMPLOEES * Random());

      Seize(Desks[x]);
      //FIXME potrebuji 4 pismenka
      Wait(Time + Uniform(30, 45));
      Release(Desks[x]);
std::cerr << "HOWK44\n"; //FIXME

      /* we are done */
      parent->Activate();
    }
  public:
    //Crate(Order &_parent, int _prior) :
    //  parent(_parent), p(_prior), start_batch(false)
    //Crate(Priority_t p=DEFAULT_PRIORITY, Order &_parent) :
    //  Entity(p), parent(_parent), start_batch(false)
    Crate(Priority_t _prior, Order *_parent) :
      Process(_prior), parent(_parent), start_batch(false)
    {
      Activate();
    }

    //static void Alloc()
    //{
    //  new Crate;
    //}
};

void Order::Behavior()
{
  int t = Time;

  /* crates are for single letters; one advert is from 4 letters */
  int crates = (count * 4) / CRATE_VOL_MAX +
             (((count * 4) % CRATE_VOL_MAX == 0) ? 0 : 1);

  //FIXME mame plny sklad plexi desek (dokumentace: desky objednavany
  //  v dostatecnem predstihu, takze tady problem nebyl)
  /* divide the order into crates and let them cross the system
     independently */
  for (int i = 0; i < crates; ++i)
  {
    new Crate(Priority, this);
  }
  //Crate crate = new Crate(Priority, this);

  /* needed crates */
  int handled_crates = 0;

  // FIXME cekej, az obdrzis signal od vsech crate, ktere jsi vytvoril
  /* wait until all crates are done */
  while (handled_crates < crates)
  {
std::cerr << "HOWK00 order\n"; //FIXME
    Passivate();
std::cerr << "HOWK11 order\n"; //FIXME
    ++crates;
  }

  /* order correctly served */
  //FIXME vypsat celkovy cas v systemu (duration)
  std::cout << "Order " << id << " with priority " << (int)Priority \
    << " served in " << Time - t << " minutes.\n";
}

Order::Order(Priority_t _prior, int _count) :
  Process(_prior), count(_count), id(OrderID++)
{
  Activate();
}

void Order::Alloc(Entity::Priority_t _prior, int _count)
{
  new Order(_prior, _count);
}

int main()
{
  //std::ifstream f("nazev_souboru.txt");
  //if (!f) { std::cerr << "fail" << std::endl; return 1; }
  //std::cout << "Hello" << std::endl;

  //SetOutput(stdout);
  //Print("some fucking desc\n");
  //FIXME generate some of my fucking orders!
  //FIXME generator should change priority!
  /* N work days (8 hours per day) */
  Init(0, 60 * 8 * 1000);
  new Generator(Order::Alloc);
  Run();

  //Table0.Output();
  Plotter.Output();
  Grinder.Output();
  Paintshop.Output();
  for (int i = 0; i < COMPLETION_EMPLOEES; ++i)
  {
    std::cout << "FACILITY " << i +1 << "\n";
    Desks[i].Output();
  }

  return 0;
}