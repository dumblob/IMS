/**
 * Topic:   Okruh 4: SHO Vyrobni linka
 *          Vyroba reklam BOSE
 * Authors: Jan Pacner (xpacne00@stud.fit.vutbr.cz)
 *          Lukas Frencl (xfrenc00@stud.fit.vutbr.cz)
 * Date:    2012-12-01 10:56:23 CET
 */

#include <simlib.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "main.h"

int MAX(double x, double y) { return (x > y) ? x : y; }
int MIN(double x, double y) { return (y > x) ? x : y; }

const unsigned int WORKING_HOURS_N = 8;
const unsigned int WORKING_DAYS_IN_WEEK = 5;
/* service priority */
const unsigned int NON_WORKING_HOURS_SERV_PRIOR = 10;
const unsigned int GRINDER_FAILURE_SERV_PRIOR = 5;
/* mean of order volume */
const unsigned int ORDINARY_ORDER = 60;
/* max process (queue) priority */
const unsigned int MAX_ORDER_PRIOR = 3;
/* letters needed for one advertisement */
const unsigned int ADVERT_LETTERS = 4;
/* volume (in letters) of one crate */
const unsigned int CRATE_VOL_MAX = 8;
#ifdef LASER
const unsigned int PLEXI_SHEET_PARTS = 84;
#else
const unsigned int PLEXI_SHEET_PARTS = 68;
#endif
const unsigned int COMPLETION_EMPLOEES = 2;
const unsigned int STAKES_CAPACITY = 48;
unsigned int OrderID = 0;

Facility Plotter("Plexiglass plotter");
GrinderC Grinder("Plexiglass grinder");
Facility Paintshop("Plexiglass letters paintshop");
Facility Desks[COMPLETION_EMPLOEES];
GrinderFailureC GrinderFailure(Grinder);

Histogram Hist00("Average time to process 1 order", 0, 0.1, 10000);
Histogram Hist01("Average time in Plotteru", 0, 0.1, 10000);
Histogram Hist02("Average time in Grinderu", 0, 0.1, 10000);
Histogram Hist03("Average time in Paintshopu", 0, 0.1, 10000);
Histogram Hist04("Average time in one of Desks", 0, 0.1, 10000);
Histogram Hist05("Average time of processing of 1 Crate", 0, 0.1, 10000);

/** PlotterBatchC */
class PlotterBatchC : public Batch
{
  protected:
#ifdef LASER
    /* about 22 mins longer than without laser */
    int Duration() { return 75 + 22 + Uniform(25, 55); };
#else
    /* one plexi sheet insist 75 minutes of cutting */
    int Duration() { return 75 + Uniform(25, 55); };
#endif
    bool ThisCrateFailed()
    {
#ifdef LASER
      /* no failures */
      return false;
#else
      /* cca 20% of cutted letters were cracked and needed to be cut
         again from new plexiglass desk */
      return Random() < 0.20;
#endif
    }
  public:
    PlotterBatchC(Facility &_fac, unsigned int _len) : Batch(_fac, _len) { }
  /* at least (PLEXI_SHEET_PARTS / CRATE_VOL_MAX) crates are needed for
      one plotter run */
} PlotterBatch(Plotter, PLEXI_SHEET_PARTS / CRATE_VOL_MAX);

/** PaintshopBatchC */
class PaintshopBatchC : public Batch
{
  protected:
    int Duration() { return Uniform(55, 85); };
    bool ThisCrateFailed()
    {
      /* 0 to 2 bad varnished letters per 2 batches */
      return Random() < (Uniform(0, 2) / 2 /
          trunc(STAKES_CAPACITY / CRATE_VOL_MAX));
    }
  public:
    PaintshopBatchC(Facility &_fac, unsigned int _len) :
      Batch(_fac, _len) { }
} PaintshopBatch(Paintshop, trunc(STAKES_CAPACITY / CRATE_VOL_MAX));

/** WorkingHoursC */
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
  Release(Grinder); \
  Release(Paintshop); \
  for (int j = 0; j < COMPLETION_EMPLOEES; ++j) \
    Release(Desks[j]); \
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
      Wait(WORKING_HOURS_N * 60);

      generator.sleeping = true;
      /* no need to pause plotter, because generator is paused */
      PaintshopBatch.waiting = true;
      SEIZE_ALL_FACILITIES;
      Wait((24 - WORKING_HOURS_N) * 60);
      RELEASE_ALL_FACILITIES;
      PaintshopBatch.waiting = false;
      generator.sleeping = false;
    }

    /* saturday, sunday */
    generator.sleeping = true;
    PaintshopBatch.waiting = true;
    SEIZE_ALL_FACILITIES;
    Wait((days_in_week - WORKING_DAYS_IN_WEEK) * 24 * 60);
    RELEASE_ALL_FACILITIES;
    PaintshopBatch.waiting = false;
    generator.sleeping = false;
  }
}

/** Generator */
void Generator::Behavior()
{
  if (! sleeping)
  {
    /* generate order (priority, order_volume); most orders have prior. 0 */
    alloc(MIN(Exponential(0.5), MAX_ORDER_PRIOR),
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
  ScheduleFailure();
}

void GrinderC::Output()
{
  Facility::Output();
}

void GrinderC::Seize(Entity *e, ServicePriority_t sp=DEFAULT_PRIORITY)
{
  Facility::Seize(e, sp);

  /* let myself be seized by failure process */
  if (cur_n >= fail_after)
  {
    GrinderFailure.Activate();
    ScheduleFailure();
  }
  else
  {
    cur_n += CRATE_VOL_MAX;
  }
}

void GrinderC::ScheduleFailure()
{
  /* after N grinded letters */
  fail_after = Uniform(50, 80);
  cur_n = 0;
}

/** Grinder failure */
void GrinderFailureC::Behavior()
{
  for (;;)
  {
    Seize(fac, GRINDER_FAILURE_SERV_PRIOR);
    /* creation and exchange of new tool */
    Wait(Uniform(20, 30));
    Release(fac);
    Passivate();
  }
}

GrinderFailureC::GrinderFailureC(GrinderC &_fac) :
  Process(), fac(_fac)
{
  Passivate();
}

/** Batch */
void Batch::Behavior()
{
  for (;;)
  {
    if (Busy())
    {
      Seize(fac);
      waiting = true;
      Wait(Duration());
      waiting = false;
      Release(fac);

      Queue fail_q;

      /* descending, although no process can switch context and change
         the len in between */
      for (int i = len; i > 0; --i)
      {
        Entity *item = q.GetFirst();

        if (ThisCrateFailed())
          fail_q.InsLast(item);
        else
          item->Activate();
      }

      /* the failed crate has sort of highest priority */
      while (! fail_q.Empty())
        q.InsFirst(fail_q.GetFirst());
    }

    if (! Busy()) Passivate();
  }
}

Batch::Batch(Facility &_fac, unsigned int _len) :
  fac(_fac), len(_len), Process(), waiting(false)
{
  Activate();
}

void Batch::Output()
{
  std::cout << "BATCH len " << len << "\n";
  Process::Output();
  q.Output();
}

int Batch::Duration()
{
  return 0;
}

bool Batch::ThisCrateFailed()
{
  return false;
}

bool Batch::Busy()
{
  return q.Length() >= len;
}

void Batch::AddAndPassivate(Process *item)
{
  q.InsLast(item);
  if (! waiting) Activate();
  item->Passivate();
}

/*                        (60.0 * 24.0 * (365.25 / 12.0) * 12.0) */
#define MINUTES_IN_YEAR   (60.0 * 24.0 * 365.25)
#define MINUTES_IN_MONTH  (60.0 * 24.0 * (365.25 / 12.0))
#define MINUTES_IN_DAY    (60.0 * 24.0)
#define MINUTES_IN_HOUR   (60.0)

/** print time user-friendly from given minutes count */
void print_duration(double m)
{
  double Y = trunc(m / MINUTES_IN_YEAR  ); m -= Y * MINUTES_IN_YEAR;
  double M = trunc(m / MINUTES_IN_MONTH ); m -= M * MINUTES_IN_MONTH;
  double D = trunc(m / MINUTES_IN_DAY   ); m -= D * MINUTES_IN_DAY;
  double h = trunc(m / MINUTES_IN_HOUR  ); m -= h * MINUTES_IN_HOUR;

  /* normalize according to our time management */
  double tmp;
  tmp = trunc(h / WORKING_HOURS_N); h -= tmp * WORKING_HOURS_N;
  D += tmp;
  tmp = trunc(D / (365.25 / 12.0)); D -= tmp * (365.25 / 12.0);
  M += tmp;
  tmp = trunc(M / 12.0); M -= tmp * 12.0;
  Y += tmp;

  printf("%d years %d months %d days %02d:%02d%s",
      (int)Y, (int)M, (int)D, (int)h, (int)m,
      ((int)Y == 0 &&
       (int)M == 0 &&
       (int)D == 0 &&
       (int)h == 0 &&
       (int)m == 0) ? " (approaching zero)" : "");
}

/** Order */
void Order::Behavior()
{
  double t = Time;

  /* crates are for single letters; one advert is from 4 letters */
  int crates = (count * 4) / CRATE_VOL_MAX +
             (((count * 4) % CRATE_VOL_MAX == 0) ? 0 : 1);

  /* divide the order into crates and let them cross the system
     independently */
  for (int i = 0; i < crates; ++i)
    new Crate(Priority, this);

  /* needed crates */
  int handled_crates = 0;

  /* wait until all crates are done */
  while (handled_crates < crates)
  {
    Passivate();
    ++handled_crates;
  }

  /* order correctly served */
  std::cout << "Order " << id << " with priority " << (int)Priority \
    << " served in ";
  print_duration(Time - t);
  std::cout << "\n";

  Print("%d %lf\n", count, Time - t);
  Hist00(Time - t);
}

Order::Order(Priority_t _prior, int _count) :
  Process(_prior), count(_count), id(OrderID++)
{
  std::cout << "NEW order [" << id << "] for " << _count <<
    " items with queue prior " << (int)_prior << "\n";
  Activate();
}

void Order::Alloc(Entity::Priority_t _prior, int _count)
{
  new Order(_prior, _count);
}

/** Crate */
void Crate::Behavior()
{
  double t_whole = Time;

  double t_plotter = Time;
  PlotterBatch.AddAndPassivate(this);
  t_plotter = Time - t_plotter;

  double t_grinder = Time;
  /* each letter takes its own time */
  Seize(Grinder);
  for (int i = 0; i < CRATE_VOL_MAX; ++i)
#ifdef LASER
    Wait(Uniform(10, 15));
#else
    Wait(Uniform(8, 12));
#endif
  Release(Grinder);
  t_grinder = Time - t_grinder;

  double t_paintshop = Time;
  /* 9 paint layers */
  for (int i = 0; i < 9; ++i)
  {
    PaintshopBatch.AddAndPassivate(this);
    /* next layer after 60 minutes */
    Wait(60);
  }

  /* wait for final paint dry; -60 because we already waited that long */
  Wait(Uniform(20, 24) * 60 -60);
  t_paintshop = Time - t_paintshop;

  /* get some free desk */
  int x = int(COMPLETION_EMPLOEES * Random());

  double t_desks = Time;
  Seize(Desks[x]);
  /* finish adverts from the whole crate */
  for (int i = 0; i < CRATE_VOL_MAX / ADVERT_LETTERS; ++i)
    Wait(Uniform(55, 70));
  Release(Desks[x]);

  /* now, it is an atomic operation (without context switching) */
  Hist01(t_plotter);
  Hist02(t_grinder);
  Hist03(t_paintshop);
  Hist04(Time - t_desks);
  Hist05(Time - t_whole);

  /* we are done */
  parent->Activate();
}

Crate::Crate(Priority_t _prior, Order *_parent) :
  Process(_prior), parent(_parent), start_batch(false)
{
  Activate();
}

/**
 * argv[1] count of months to simulate
 * argv[2] prefix for simulation files
 */
int main(int argc, char *argv[])
{
  SetOutput((std::string(argv[2]) + "a.dat").c_str());
  Print("# experiment XYZ\n");

  /* order duration */
  std::ofstream orderdur((std::string(argv[2]) + "b.dat").c_str(), std::ios::app);
  if (! orderdur.is_open())
  {
    std::cerr << "failed to open orderdur" << std::endl;
    return 1;
  }

  /* facility congestion */
  std::ofstream faccongestion((std::string(argv[2]) + "c.dat").c_str(), std::ios::out);
  if (! faccongestion.is_open())
  {
    std::cerr << "failed to open faccongestion" << std::endl;
    return 1;
  }

  //Debug(5);

  /* 1 crate can contain only letters for whole advertisements */
  assert(CRATE_VOL_MAX % ADVERT_LETTERS == 0);

  /* how many months? */
  double dur = (365.25 / 12) * atol(argv[1]) * 24 * 60;

  RandomSeed(time(NULL));
  Init(0, (long)dur);
  Generator *G = new Generator(Order::Alloc);
  WorkingHoursC *WorkingHours = new WorkingHoursC(*G);
  Run();

  /* average time of processing of 1 order X duration of that manufacture run */
  orderdur << (long)dur << " " << Hist00.stat.MeanValue() << "\n";
  std::cout << "average time to process 1 order: " <<
    Hist00.stat.MeanValue() << "(";
  print_duration(Hist00.stat.MeanValue());
  std::cout << ")\n";

  /* average load of facilities in time */
  faccongestion << "0 Plotter "   << (Hist01.stat.MeanValue() / Hist05.stat.MeanValue()) * 100 << "\n";
  faccongestion << "1 Grinder "   << (Hist02.stat.MeanValue() / Hist05.stat.MeanValue()) * 100 << "\n";
  faccongestion << "2 Paintshop " << (Hist03.stat.MeanValue() / Hist05.stat.MeanValue()) * 100 << "\n";
  faccongestion << "3 Desks "     << (Hist04.stat.MeanValue() / Hist05.stat.MeanValue()) * 100 << "\n";

#ifdef DEBUGG
  Print("\n\n");

  tbl00.Output();
  Plotter.Output();
  Print("Plotter batch\n");
  PlotterBatch.Output();
  Print("\n\n");

  Grinder.Output();
  GrinderFailure.Output();
  Print("\n\n");

  Paintshop.Output();
  Print("Paintshop batch\n");
  PaintshopBatch.Output();
  Print("\n\n");

  for (int i = 0; i < COMPLETION_EMPLOEES; ++i)
  {
    std::cout << "FACILITY " << i +1 << "\n";
    Desks[i].Output();
    Print("\n\n");
  }
#endif

  orderdur.close();
  faccongestion.close();

  return 0;
}
