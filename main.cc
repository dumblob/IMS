/**
 * Topic:   Okruh 4: SHO Vyrobni linka
 *          Vyroba reklam BOSE
 * Authors: Jan Pacner (xpacne00@stud.fit.vutbr.cz)
 *          Lukas Frencl (xfrenc00@stud.fit.vutbr.cz)
 * Date:    2012-12-01 10:56:23 CET
 */

//FIXME TODO
//  namodelovat pracovni tyden (lze nastavit dobu mezi koncem pracovni smeny
//    a zacatkem dalsi smeny - napr. pro modelovani vikendu, svatku,
//    prodlouzenych a zkracenych pracovnich dob apod.)
//  pridat nahodne chyby v lakovne
//  obrovsky vypadek elektriny (jako v realu u Drapace)
//    == proces, ktery proste jednou za cas s nejvyssi prioritou obsadi
//    vsechna elektronicka zarizeni

#include <simlib.h>
#include <iostream>
#include <assert.h>
#include "main.h"
//#include <fstream>

int MAX(double x, double y) { return (x > y) ? x : y; }
int MIN(double x, double y) { return (y > x) ? x : y; }

const unsigned int WORKING_HOURS_N = 8;
const unsigned int WORKING_DAYS_IN_WEEK = 5;
/* service priority */
const unsigned int NON_WORKING_HOURS_SERV_PRIOR = 99;
/* the mean order volume */
const unsigned int ORDINARY_ORDER = 60;
/* process (queue) priority */
const unsigned int MAX_ORDER_PRIOR = 4;
/* letters needed for one advertisement */
const unsigned int ADVERT_LETTERS = 4;
/* volume (in letters) of one crate */
const unsigned int CRATE_VOL_MAX = 8;
const unsigned int PLEXI_SHEET_PARTS = 68;
const unsigned int COMPLETION_EMPLOEES = 2;
const unsigned int STAKES_CAPACITY = 48;
unsigned int OrderID = 0;
Histogram Table0("Muj nazev", 0, 0.1, 20); //FIXME

Facility Plotter("Plexiglass plotter");
GrinderC Grinder("Plexiglass grinder");
Facility Paintshop("Plexiglass letters paintshop");
Facility Desks[COMPLETION_EMPLOEES];

/** WorkingHoursC */
//WorkingHoursC::WorkingHoursC(Priority_t _p) :
//  Process(_p)
WorkingHoursC::WorkingHoursC(Generator &_g) :
  Process(), generator(_g)
{
  Activate();
}

#define SEIZE_ALL_FACILITIES { \
  Seize(Plotter, NON_WORKING_HOURS_SERV_PRIOR); \
  Seize(Grinder, NON_WORKING_HOURS_SERV_PRIOR); \
  Seize(Paintshop, NON_WORKING_HOURS_SERV_PRIOR); \
  for (int j = 0; j < COMPLETION_EMPLOEES; ++j) \
    Seize(Desks[j], NON_WORKING_HOURS_SERV_PRIOR); \
}

#define RELEASE_ALL_FACILITIES { \
  Release(Plotter); \
  std::cerr << "___ after plotter\n"; \
  Release(Grinder); \
  std::cerr << "___ after grinder\n"; \
  Release(Paintshop); \
  std::cerr << "___ after paintshop\n"; \
  for (int j = 0; j < COMPLETION_EMPLOEES; ++j) \
    Release(Desks[j]); \
  std::cerr << "___ after both desks\n"; \
}

/* one week simulation */
void WorkingHoursC::Behavior()
{
  unsigned short days_in_week = 7;
  assert(WORKING_DAYS_IN_WEEK <= days_in_week);
  assert(WORKING_HOURS_N <= 24);

  for (;;)
  {
    /* 5 working days */
    for (int i = 0; i < WORKING_DAYS_IN_WEEK; ++i)
    {
      //Wait(10);//FIXME
      Wait(WORKING_HOURS_N * 60);
  std::cerr << "working hours 00\n";//FIXME

      generator.sleeping = true;
      SEIZE_ALL_FACILITIES;
  std::cerr << "working hours 11\n";//FIXME
      Wait((24 - WORKING_HOURS_N) * 60);
  std::cerr << "working hours 22\n";//FIXME
      RELEASE_ALL_FACILITIES;
      generator.sleeping = false;
  std::cerr << "working hours 33\n";//FIXME
    }

    /* saturday, sunday */
    generator.sleeping = true;
    SEIZE_ALL_FACILITIES;
    Wait((days_in_week - WORKING_DAYS_IN_WEEK) * 24 * 60);
    RELEASE_ALL_FACILITIES;
    generator.sleeping = false;
  }
}

/** PlotterBatchC */
class PlotterBatchC : public Batch
{
  public:
    PlotterBatchC(Facility &_fac, unsigned int _len) : Batch(_fac, _len) { }
    /* one plexi sheet insist 75 minutes of cutting */
    int Duration() { return 75 + Uniform(25, 55); };
  /* at least (PLEXI_SHEET_PARTS / CRATE_VOL_MAX) crates are needed for
      one plotter run */
} PlotterBatch(Plotter, PLEXI_SHEET_PARTS / CRATE_VOL_MAX);

/** PaintshopBatchC */
class PaintshopBatchC : public Batch
{
  public:
    PaintshopBatchC(Facility &_fac, unsigned int _len) :
      Batch(_fac, _len) { }
    int Duration() { return Uniform(45, 65); };
} PaintshopBatch(Paintshop, STAKES_CAPACITY / CRATE_VOL_MAX);

/** Generator */
void Generator::Behavior()
{
  if (! sleeping)
  {
    std::cerr << "NOT sleeping, yeah!\n";//FIXME
    //FIXME nova objednavka se vzdy vygeneruje po aktivaci - je to dobre?
    /* generate new order (priority, order_volume) */
    alloc(MIN(Exponential(MAX_ORDER_PRIOR / 3), MAX_ORDER_PRIOR),
        MAX(Exponential(ORDINARY_ORDER), 1));
  }

  /* new request/order */
  Activate(Time + Exponential(2 * WORKING_HOURS_N * 60));
}

Generator::Generator(AllocPtr_t _ptr) :
  alloc(_ptr), sleeping(true)
{
  Activate();
}

/** Grinder */
GrinderC::GrinderC(const char *_s) :
  Facility(_s)
{
  scheduleFailure();
}

void GrinderC::Output()
{
  std::cout << "grinded letters: " << cur_n << "\n";
  Facility::Output();
}

void GrinderC::Seize(Entity *e, ServicePriority_t sp=DEFAULT_PRIORITY)
{
  Facility::Seize(e, sp);
  cur_n += CRATE_VOL_MAX;
}

void GrinderC::scheduleFailure()
{
  std::cerr << "failer scheduled\n";//FIXME
  /* after N grinded letters */
  fail_after = Uniform(50, 80);
  cur_n = 0;
}

bool GrinderC::failed()
{
  return cur_n >= fail_after;
}

/** Batch */
void Batch::Behavior()
{
  for (;;)
  {
    if (Busy())
    {
      Seize(fac);
      Wait(Duration());
      Release(fac);

      for (int i = len; i != 0; --i)
        q.GetFirst()->Activate();
    }

    if (! Busy()) Passivate();
  }
}

Batch::Batch(Facility &_fac, unsigned int _len) :
  fac(_fac), len(_len), Process()
{
  Activate();
}

void Batch::Output()
{
  std::cout << "len " << len << "\n";
  Process::Output();
  q.Output();
}

int Batch::Duration()
{
  return 0;
}

bool Batch::Busy()
{
  return q.Length() >= len;
}

void Batch::AddAndPassivate(Process *item)
{
  q.InsLast(item);
  Activate();
  item->Passivate();
}

/** Order */
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
    new Crate(Priority, this);

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
  std::cerr << "new order | queue prior " << (int)_prior << "\n";//FIXME
  new Order(_prior, _count);
}

/** Crate (bedna, prepravka) */
void Crate::Behavior()
{
  PlotterBatch.AddAndPassivate(this);

  static int abc = 0; ++abc;//FIXME
  if (Grinder.failed())
  {
    std::cerr << "[" << parent->id << "] grinder failed\n"; //FIXME
    Wait(Uniform(20, 30));
    if (Grinder.failed()) Grinder.scheduleFailure();
  }

  /* each letter takes its own time */
  Seize(Grinder);
  for (int i = 0; i < CRATE_VOL_MAX; ++i)
    Wait(Uniform(9, 13));
  Release(Grinder);
  std::cerr << "[" << parent->id << "] after grinder\n"; //FIXME

  /* 9 paint layers */
  for (int i = 0; i < 9; ++i)
  {
    //FIXME chybovost lakovani!
    PaintshopBatch.AddAndPassivate(this);

    /* next layer first after 60 minutes */
    Wait(60);
  }
  std::cerr << "HOWK33\n"; //FIXME

  /* wait for final paint dry; -60 because we already waited that long */
  Wait(Uniform(20, 24) * 60 -60);

  /* get some free desk */
  int x = int(COMPLETION_EMPLOEES * Random());

  Seize(Desks[x]);
  //FIXME potrebuji 4 pismenka a ne vsechna co jsou v krabici
  Wait(Uniform(55, 70));
  Release(Desks[x]);
  std::cerr << "HOWK44\n"; //FIXME

  /* we are done */
  parent->Activate();
}

Crate::Crate(Priority_t _prior, Order *_parent) :
  Process(_prior), parent(_parent), start_batch(false)
{
  Activate();
}

int main()
{
  //std::ifstream f("nazev_souboru.txt");
  //if (!f) { std::cerr << "fail" << std::endl; return 1; }
  //std::cout << "Hello" << std::endl;

  //SetOutput(stdout);
  //Print("some fucking desc\n");

  Debug(4);

  /* 2 weeks */
  //Init(0, 12);//FIXME
  Init(0, (2 * 7) * 24 * 60);
  Generator *G = new Generator(Order::Alloc);
  new WorkingHoursC(*G);
  //new WorkingHoursC(MAX_ORDER_PRIOR +1);//FIXME
  Run();

  //Table0.Output();
  Plotter.Output();
  Print("Plotter batch\n");
  PlotterBatch.Output();

  Grinder.Output();

  Paintshop.Output();
  Print("Paintshop batch\n");
  PaintshopBatch.Output();

  for (int i = 0; i < COMPLETION_EMPLOEES; ++i)
  {
    std::cout << "FACILITY " << i +1 << "\n";
    Desks[i].Output();
  }

  return 0;
}
