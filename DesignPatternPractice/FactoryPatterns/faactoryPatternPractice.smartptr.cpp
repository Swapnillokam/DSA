#include <iostream>
#include <memory>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class BasicBurger : public Burger
{
    void prepare() override
    {
        cout << "praparing basic burger" << endl;
    }
};
class StandardBurger : public Burger
{
    void prepare() override
    {
        cout << "praparing StandardBurger burger" << endl;
    }
};
class PremiumBurger : public Burger
{
    void prepare() override
    {
        cout << "praparing PremiumBurger burger" << endl;
    }
};

class BurgerFactory
{
public:
    unique_ptr<Burger> createBurger(string &burgerType)
    {
        if (burgerType == "basic")
            return make_unique<BasicBurger>();
        else if (burgerType == "std")
            return make_unique<StandardBurger>();
        else if (burgerType == "prm")
            return make_unique<PremiumBurger>();
        return nullptr;
    }
};

int main()
{
    string burgerType = "std";
    unique_ptr<BurgerFactory> factory = make_unique<BurgerFactory>();
    factory->createBurger(burgerType)->prepare();

    return 0;
}