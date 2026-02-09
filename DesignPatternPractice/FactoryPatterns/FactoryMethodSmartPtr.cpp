#include <iostream>
#include <memory>

using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = 0;
};

Burger::~Burger()
{
    cout << "abstract destructor called" << endl;
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
    virtual unique_ptr<Burger> createBurger(string &burgerType) = 0;
};

class SinghBurger : public BurgerFactory
{
public:
    unique_ptr<Burger> createBurger(string &burgerType) override
    {
        if (burgerType == "basic")
            return make_unique<BasicBurger>();
        if (burgerType == "std")
            return make_unique<StandardBurger>();
        if (burgerType == "prm")
            return make_unique<PremiumBurger>();
        return nullptr;
    }
};

class KingBurger : public BurgerFactory
{
public:
    unique_ptr<Burger> createBurger(string &burgerType) override
    {
        if (burgerType == "basicwheat")
            return make_unique<BasicWheatBurger>();
        if (burgerType == "stdwheat")
            return make_unique<StandardWheatBurger>();
        if (burgerType == "prmwheat")
            return make_unique<PremiumWheatBurger>();
        return nullptr;
    }
};

int main()
{
    string SburgerType = "prm";
    // burger
    BurgerFactory *Sfactory = new SinghBurger();
    Sfactory->createBurger(SburgerType)->prepare();

    string KburgerType = "prmwheat";
    BurgerFactory *Kfactory = new KingBurger();
    unique_ptr<Burger> b = Kfactory->createBurger(KburgerType);
    b->prepare();
    return 0;
}