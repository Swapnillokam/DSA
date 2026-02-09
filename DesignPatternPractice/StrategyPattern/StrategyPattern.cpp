#include <iostream>

using namespace std;

class Talkable
{
public:
    virtual void talk() = 0;
    virtual ~Talkable() = 0;
};
Talkable::~Talkable()
{
    cout << "Talkable Destructor called" << endl;
}

class NormalTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Normal Talk" << endl;
    }
};
class NoTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "No Talk" << endl;
    }
};

class Walkable
{
public:
    virtual void walk() = 0;
    virtual ~Walkable() = 0;
};
Walkable::~Walkable()
{
    cout << "Walkable Destructor called" << endl;
}

class NormalWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Normal Walk" << endl;
    }
};
class NoWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "No Walk" << endl;
    }
};

class Flyable
{
public:
    virtual void fly() = 0;
    virtual ~Flyable() = 0;
};
Flyable::~Flyable()
{
    cout << "Flyable Destructor called" << endl;
}

class NormalFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Normal Fly" << endl;
    }
};
class NoFly : public Flyable
{
public:
    void fly() override
    {
        cout << "No Fly" << endl;
    }
};

class Robot
{
public:
    Walkable *w;
    Talkable *t;
    Flyable *f;

    Robot(Walkable *w, Talkable *t, Flyable *f)
    {
        this->w = w;
        this->t = t;
        this->f = f;
    }

    virtual void projection() = 0;

    void walk()
    {
        w->walk();
    }

    void talk()
    {
        t->talk();
    }

    void fly()
    {
        f->fly();
    }

    virtual ~Robot()
    {
        cout << "Robot destructor called" << endl;
        delete w;
        delete t;
        delete f;
    }
};

class CompanionRobot : public Robot
{
public:
    CompanionRobot(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f)
    {
    }

    void projection() override
    {
        cout << "CompanionRobot stats" << endl;
    }
};
class WorkerRobot : public Robot
{
public:
    WorkerRobot(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f)
    {
    }

    void projection() override
    {
        cout << "WorkerRobot stats" << endl;
    }
};

int main()
{
    Talkable *nt = new NoTalk();
    Walkable *nw = new NoWalk();
    Flyable *nf = new NoFly();
    Robot *r = new CompanionRobot(nw, nt, nf);
    r->projection();
    r->walk();
    r->talk();
    r->fly();

    delete r;

    cout << endl;

    Talkable *t = new NormalTalk();
    Walkable *w = new NormalWalk();
    Flyable *f = new NormalFly();
    Robot *r2 = new WorkerRobot(w, t, f);
    r2->projection();
    r2->walk();
    r2->talk();
    r2->fly();

    delete r2;

    return 0;
}