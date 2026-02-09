#include <iostream>
#include <memory>

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
    unique_ptr<Walkable> w;
    unique_ptr<Talkable> t;
    unique_ptr<Flyable> f;

    Robot(unique_ptr<Walkable> w, unique_ptr<Talkable> t, unique_ptr<Flyable> f) : w(move(w)), t(move(t)), f(move(f))
    {
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
    }
};

class CompanionRobot : public Robot
{
public:
    CompanionRobot(unique_ptr<Walkable> w, unique_ptr<Talkable> t, unique_ptr<Flyable> f) : Robot(move(w), move(t), move(f))
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
    WorkerRobot(unique_ptr<Walkable> w, unique_ptr<Talkable> t, unique_ptr<Flyable> f) : Robot(move(w), move(t), move(f))
    {
    }

    void projection() override
    {
        cout << "WorkerRobot stats" << endl;
    }
};

int main()
{
    unique_ptr<Talkable> nt = make_unique<NoTalk>();
    unique_ptr<Walkable> nw = make_unique<NoWalk>();
    unique_ptr<Flyable> nf = make_unique<NoFly>();
    unique_ptr<Robot> r = make_unique<CompanionRobot>(move(nw), move(nt), move(nf));
    r->projection();
    r->walk();
    r->talk();
    r->fly();

    cout << endl;

    unique_ptr<Talkable> t = make_unique<NormalTalk>();
    unique_ptr<Walkable> w = make_unique<NormalWalk>();
    unique_ptr<Flyable> f = make_unique<NormalFly>();
    unique_ptr<Robot> r2 = make_unique<WorkerRobot>(move(w), move(t), move(f));
    r2->projection();
    r2->walk();
    r2->talk();
    r2->fly();

    return 0;
}