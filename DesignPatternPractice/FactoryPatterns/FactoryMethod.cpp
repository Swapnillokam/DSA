#include <iostream>

using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = 0;
};

Burger::~Burger()
{
    cout << "abstract factory destructor called" << endl;
}

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing BasicBurger" << endl;
    }
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing StandardBurger" << endl;
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing PremiumBurger" << endl;
    }
};
class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing BasicWheatBurger" << endl;
    }
};
class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing StandardWheatBurger" << endl;
    }
};
class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing PremiumWheatBurger" << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *createBurger(string &burgerType) = 0;
    virtual ~BurgerFactory() { cout << "abstract Burger Factory destructor" << endl; }
};

class SinghBurger : public BurgerFactory
{
public:
    Burger *createBurger(string &burgerType) override
    {
        if (burgerType == "basic")
            return new BasicBurger();
        if (burgerType == "std")
            return new StandardBurger();
        if (burgerType == "prm")
            return new PremiumBurger();
        return nullptr;
    }
};

class KingBurger : public BurgerFactory
{
public:
    Burger *createBurger(string &burgerType) override
    {
        if (burgerType == "basicwheat")
            return new BasicWheatBurger();
        if (burgerType == "stdwheat")
            return new StandardWheatBurger();
        if (burgerType == "prmwheat")
            return new PremiumWheatBurger();
        return nullptr;
    }
};

int main()
{
    string SburgerType = "prm";
    // burger
    BurgerFactory *Sfactory = new SinghBurger();
    Sfactory->createBurger(SburgerType)->prepare();
    delete Sfactory;

    string KburgerType = "prmwheat";
    BurgerFactory *Kfactory = new KingBurger();
    Burger *b = Kfactory->createBurger(KburgerType);
    b->prepare();
    delete Kfactory;
    delete b;
    return 0;
}