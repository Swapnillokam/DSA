// #include <iostream>
// #include <memory>

// using namespace std;

// class Talkable
// {
// public:
//     virtual void talk() = 0;
//     // virtual ~Talkable() = 0;
//     virtual ~Talkable() = default;
// };

// /* Talkable::~Talkable()
// {
//     cout << "destructor for talkable class" << endl;
// }
//  */
// class Talk : public Talkable
// {
// public:
//     void talk() override
//     {
//         cout << "robot can talk" << endl;
//     }
// };

// class NoTalk : public Talkable
// {
// public:
//     void talk() override
//     {
//         cout << "robot canot talk" << endl;
//     }
// };

// class Walkable
// {
// public:
//     virtual void walk() = 0;
//     // virtual ~Walkable() = 0;
//     virtual ~Walkable() = default;
// };

// /* Walkable::~Walkable()
// {
//     cout << "destructor for Walkable class" << endl;
// } */

// class Walk : public Walkable
// {
// public:
//     void walk() override
//     {
//         cout << "robot can walk" << endl;
//     }
// };

// class NoWalk : public Walkable
// {
// public:
//     void walk() override
//     {
//         cout << "robot cannot walk" << endl;
//     }
// };

// class Flyable
// {
// public:
//     virtual void fly() = 0;
//     // virtual ~Flyable() = 0;
//     virtual ~Flyable() = default;
// };
// /*
// Flyable::~Flyable()
// {
//     cout << "destructor for Flyable class" << endl;
// } */

// class Fly : public Flyable
// {
// public:
//     void fly() override
//     {
//         cout << "robot can fly" << endl;
//     }
// };

// class NoFly : public Flyable
// {
// public:
//     void fly() override
//     {
//         cout << "robot cannot fly" << endl;
//     }
// };

// class Robot
// {
// public:
//     /* Talkable *t;
//     Walkable *w;
//     Flyable *f;

//     Robot(Talkable *t, Walkable *w, Flyable *f)
//     {
//         this->t = t;
//         this->w = w;
//         this->f = f;
//     }

//     virtual ~Robot()
//     {
//         delete t;
//         delete w;
//         delete f;
//     } */

//     unique_ptr<Talkable> t;
//     unique_ptr<Walkable> w;
//     unique_ptr<Flyable> f;

//     Robot(unique_ptr<Talkable> t, unique_ptr<Walkable> w, unique_ptr<Flyable> f) : t(move(t)), w(move(w)), f(move(f))
//     {
//     }

//     void talk()
//     {
//         t->talk();
//     }

//     void walk()
//     {
//         w->walk();
//     }

//     void fly()
//     {
//         f->fly();
//     }

//     virtual void projection() = 0;

//     virtual ~Robot() = default;
// };

// class Companion : public Robot
// {
// public:
//     // Companion(Talkable *t, Walkable *w, Flyable *f) : Robot(t, w, f) {}
//     Companion(unique_ptr<Talkable> t, unique_ptr<Walkable> w, unique_ptr<Flyable> f) : Robot(move(t), move(w), move(f)) {}

//     void projection() override
//     {
//         cout << "companion robot stats" << endl;
//     }
// };

// int main()
// {
//     /* Talkable *nt = new NoTalk();
//     Walkable *nw = new NoWalk();
//     Flyable *nf = new NoFly();
//     Robot *r = new Companion(nt, nw, nf);
//     r->projection();
//     r->talk();
//     r->walk();
//     r->fly();

//     delete r; */
//     auto nt = make_unique<NoTalk>();
//     auto nw = make_unique<NoWalk>();
//     auto nf = make_unique<NoFly>();
//     auto r = make_unique<Companion>(move(nt), move(nw), move(nf));
//     r->projection();
//     r->talk();
//     r->walk();
//     r->fly();
//     return 0;
// }

/* #include <iostream>
#include <memory>

using namespace std;
class Walkable
{
public:
    virtual void walk() = 0;
    virtual ~Walkable() = 0;
};

Walkable::~Walkable()
{
    cout << "walkable destructor called" << endl;
}

class Walk : public Walkable
{
public:
    void walk() override
    {
        cout << "robot can walk" << endl;
    }
};

class NoWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "robot cannot walk" << endl;
    }
};

class Talkable
{
public:
    virtual void talk() = 0;
    virtual ~Talkable() = 0;
};

Talkable::~Talkable()
{
    cout << "Talkable destructor called" << endl;
}

class Talk : public Talkable
{
public:
    void talk() override
    {
        cout << "robot can Talk" << endl;
    }
};

class NoTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "robot cannot Talk" << endl;
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
    cout << "Talkable destructor called" << endl;
}

class Fly : public Flyable
{
public:
    void fly() override
    {
        cout << "robot can Talk" << endl;
    }
};

class NoFly : public Flyable
{
public:
    void fly() override
    {
        cout << "robot cannot Talk" << endl;
    }
};

class Robot
{
public:
    Talkable *t;
    Walkable *w;
    Flyable *f;

    Robot(Talkable *t, Walkable *w, Flyable *f)
    {
        this->t = t;
        this->w = w;
        this->f = f;
    }

    void talk()
    {
        t->talk();
    }
    void walk()
    {
        w->walk();
    }
    void fly()
    {
        f->fly();
    }

    ~Robot()
    {
        delete t;
        delete w;
        delete f;
    }
};

class Companion : public Robot
{
public:
    Companion(Talkable *t, Walkable *w, Flyable *f) : Robot(t, w, f) {}
};

int main()
{

    Robot *r = new Companion(new NoTalk(), new NoWalk(), new NoFly());
    r->talk();
    r->walk();
    r->fly();
    delete r;
} */

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "MyClass.h"

using namespace std;

class IBurger
{
public:
    virtual void prepare() = 0;
    virtual ~IBurger() = 0;
};

IBurger::~IBurger()
{
    cout << "Iburger destructor called" << endl;
}

class BasicBurger : public IBurger
{
public:
    void prepare() override
    {
        cout << "prapring BasicBurger" << endl;
    }
};
class StdBurger : public IBurger
{
public:
    void prepare() override
    {
        cout << "prapring StdBurger" << endl;
    }
};
class PrmBurger : public IBurger
{
public:
    void prepare() override
    {
        cout << "prapring PrmBurger" << endl;
    }
};

class KingBasicBurger : public IBurger
{
public:
    void prepare() override
    {
        cout << "prapring KingBasicBurger" << endl;
    }
};
class KingStdBurger : public IBurger
{
public:
    void prepare() override
    {
        cout << "prapring KingStdBurger" << endl;
    }
};
class KingPrmBurger : public IBurger
{
public:
    void prepare() override
    {
        cout << "prapring KingPrmBurger" << endl;
    }
};

class BurgerFactory
{
public:
    /* IBurger *createBurger(string burgerType)
    {
        if (burgerType == "basic")
            return new BasicBurger();
        else if (burgerType == "std")
            return new StdBurger();
        else if (burgerType == "prm")
            return new PrmBurger();
        else
            return nullptr;9
    } */
    virtual IBurger *createBurger(string burgerType) = 0;
    virtual ~BurgerFactory() = 0;
};
BurgerFactory::~BurgerFactory()
{
    cout << "BurgerFactory destructor called" << endl;
}

class KingBurger : public BurgerFactory
{
public:
    IBurger *createBurger(string burgerType)
    {
        if (burgerType == "basic")
            return new KingBasicBurger();
        else if (burgerType == "std")
            return new KingStdBurger();
        else if (burgerType == "prm")
            return new KingPrmBurger();
        else
            return nullptr;
    }
};

class SinghBurger : public BurgerFactory
{
public:
    IBurger *createBurger(string burgerType)
    {
        if (burgerType == "basic")
            return new BasicBurger();
        else if (burgerType == "std")
            return new StdBurger();
        else if (burgerType == "prm")
            return new PrmBurger();
        else
            return nullptr;
    }
};

int main()
{
    /* BurgerFactory *factory = new KingBurger();
    IBurger *f = factory->createBurger("basic");
    f->prepare();

    factory = new SinghBurger();
    IBurger *f2 = factory->createBurger("basic");
    f2->prepare();
    delete factory; */
    /* auto add = [](int a, int b)
    {
        return a + b;
    }; */
    // cout << add(2, 3) << endl;

    /*  vector<int> v = {5, 7, 2, 4, 9};
     sort(v.begin(), v.end(),[](int a, int b){return a+b;});
     for (auto i : v)
     {
         cout << i << " ";
     } */

    /*  int x = 10;
     [x]()
     { cout << x << endl; }(); */

    /* try
    {
        throw 10.5;
        throw "swapnil";
    }
    catch (int x)
    {
        cout << "int " << x << endl;
    }
    catch (double x)
    {
        cout << "double " << x << endl;
    }
    catch (const char *x)
    {
        cout << "const char* " << x << endl;
    }
    catch (...)
    {
        cout << "caugh all" << endl;
    }
 */
    MyClass obj;
    obj.sayHello();
    //use this command to run the build and run the .exe
    //g++ Test.cpp MyClass.cpp -o Test.exe && Test.exe
    return 0;
}