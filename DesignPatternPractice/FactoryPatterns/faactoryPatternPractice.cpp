#include <iostream>
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
    Burger *createBurger(string &burgerType)
    {
        if (burgerType == "basic")
            return new BasicBurger();
        else if (burgerType == "std")
            return new StandardBurger();
        else if (burgerType == "prm")
            return new PremiumBurger();
        return nullptr;
    }
};

int main()
{
    string burgerType = "std";
    BurgerFactory *factory = new BurgerFactory();
    factory->createBurger(burgerType)->prepare();
    
    
    string burgerType2 = "prm";
    BurgerFactory f2;
    Burger *b = f2.createBurger(burgerType2);
    b->prepare();
    return 0;
}