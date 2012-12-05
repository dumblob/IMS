/**
 * Topic:   Okruh 4: SHO Vyrobni linka
 *          Vyroba reklam BOSE
 * Authors: Jan Pacner (xpacne00@stud.fit.vutbr.cz)
 *          Lukas Frencl (xfrenc00@stud.fit.vutbr.cz)
 * Date:    2012-12-01 10:56:23 CET
 */

/* ptr to static method */
typedef void (*AllocPtr_t)(Entity::Priority_t, int);

/* reused from SIMLIB example "centrala.cc" */
class Generator : public Event
{
  protected:
    AllocPtr_t alloc;
    void Behavior();
  public:
    bool sleeping;
    Generator(AllocPtr_t);
};

class WorkingHoursC : public Process
{
  private:
    Generator &generator;
    void Behavior();
  public:
    WorkingHoursC(Generator &);
};

class GrinderC: public Facility
{
  public:
    /* planned failure */
    unsigned int fail_after;
    /* current count of grinded letters */
    unsigned int cur_n;

    GrinderC(const char *);
    void Output();
    void Seize(Entity *, ServicePriority_t);
    void scheduleFailure();
    bool failed();
};

/* fifo batch */
class Batch: public Process
{
  protected:
    Queue q;
    Facility &fac;
    const int len;
    void Behavior();

  public:
    Batch(Facility &, unsigned int);
    void Output();
    virtual int Duration();
    bool Busy();
    void AddAndPassivate(Process *);
};

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

class Crate: public Process
{
  protected:
    /* parent */
    Order *parent;
    bool start_batch;
    void Behavior();
  public:
    Crate(Priority_t, Order *);
};
