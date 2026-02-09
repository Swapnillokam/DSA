#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;
class OrderBuilder
{

public:
    string employee_name;
    int emp_id;
    OrderBuilder(string empName, int empId) : employee_name(empName), emp_id(empId)
    {
        cout << "Order Builder constructor called" << endl;
    }
    ~OrderBuilder()
    {
        cout << "Order Builder destructor called" << endl;
    }
};

class Strategy
{
    double order_qty, price;
    string user_name;
    OrderBuilder *ob;

public:
    Strategy(double quantity, double orderPrice, string name) : order_qty(quantity), price(orderPrice), user_name(name)
    {
        cout << "Strategy constructor called" << endl;
        OrderBuilder *obj = new OrderBuilder("swapnil", 174);
        ob = obj;
    }

    void printValues()
    {
        cout << "order_qty = " << order_qty << endl;
        cout << "price = " << price << endl;
        cout << "user_name = " << user_name << endl;
        cout << "ob->emp_id = " << ob->emp_id << endl;
        cout << "ob->employee_name = " << ob->employee_name << endl;
    }
    ~Strategy()
    {
        cout << "Strategy destructor called" << endl;
        delete ob;
    }

    // copy constructor
    Strategy(const Strategy &obj) : order_qty(obj.order_qty), price(obj.price), user_name(obj.user_name)
    {
        cout << "copy constructor called" << endl;
        ob = new OrderBuilder(obj.ob->employee_name, obj.ob->emp_id);
    }
};

// operator overlaoding
class Complex
{

public:
    int real, img;
    Complex(int realNum, int imgNum) : real(realNum), img(imgNum)
    {
    }

    Complex() {}

    Complex operator+(const Complex &obj)
    {
        Complex result;
        result.real = real + obj.real;
        result.img = img + obj.img;
        return result;
    }
};

class Test
{
public:
    int *data;
    // int *array;
    Test(int value)
    {
        data = new int(value);
        /* array = new int[10];
        for (int i = 0; i < 10; i++)
        {
            array[i] = i+1;
        } */
    }
    Test(const Test &other)
    {
        cout << "Copy constructor called" << endl;
        data = new int(*other.data);
    }
    Test &operator=(const Test &other)
    {
        cout << "Copy assignment operator called" << endl;
        if (this != &other)
        {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
    ~Test()
    {
        delete data;
    }
};

class Sample
{
public:
    Sample() { cout << "Sample Construcetor called" << endl; }
    ~Sample() { cout << "Sample desstrutor called" << endl; }
    // shared_ptr<Sample> next;
    weak_ptr<Sample> next;
};

void addNumbers(int a, int b)
{
    int sum = a + b;
    cout << "sum = " << sum << endl;
}

void diffNumbers(int a, int b)
{
    int diff = a - b;
    cout << "diff = " << diff << endl;
}

int balance = 100;
void increasebalance(int amount)
{
    // mtx.lock();
    lock_guard<mutex> lock(mtx);
    balance += amount;
    cout << "balance = " << balance << endl;
    // mtx.unlock();
}

class Singleton
{
    static Singleton *instance;

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            mtx.lock();
            instance = new Singleton();
            mtx.unlock();
        }
        return instance;
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    try
    {
        /* cout << endl;
        Strategy *s1 = new Strategy(100, 30, "CPP");
        s1->printValues();
        cout << endl;
        Strategy s2(*s1);
        s2.printValues();
        cout << endl;
        Strategy *s3 = new Strategy(*s1);
        s3->printValues();
        delete s1; */

        // operator overlaoding
        /* Complex c1(10, 10);
        Complex c2(20, 20);
        Complex c3 = c1 + c2;
        cout << "c3.img = "<<c3.img << " c3.real = "<<c3.real << endl; */

        // rule 3
        // Test t1(20);
        // cout << "*t1.data = " << *t1.data << endl;
        // Test t2(t1);
        // cout << "*t2.data = " << *t2.data << endl;
        // Test t3(50);
        // t2 = t3;
        // cout << "*t2.data = " << *t2.data << endl;
        // /* for (int i = 0; i < 10; i++)
        // {
        //     cout << t1.array[i] << " ";
        // } */

        // smart Pointers
        /* unique_ptr<int> u1 = make_unique<int>(10);
        cout << " *u1 = " << *u1 << endl;
        cout << " u1 = " << u1 << endl;

        unique_ptr<int> u2 = move(u1);
        cout << " *u2 = " << *u2 << endl;
        cout << " u2 = " << u2 << endl;
        // cout << " *u1 = " << *u1 << endl;    //throws error
        // cout << " u1 = " << u1 << endl;

        shared_ptr<int> s1 = make_shared<int>(20);
        shared_ptr<int> s2 = s1;
        cout << " *s2 = " << *s2 << endl;
        cout << " s2 = " << s2 << endl;
        cout << " *s1 = " << *s1 << endl;
        cout << " s1 = " << s1 << endl;

        // weak_ptr<int> w1 = s1;

        cout << "s1.use_count() = " << s1.use_count();
        shared_ptr<Sample> SM1(new Sample);
        shared_ptr<Sample> SM2(new Sample);
        SM1->next = SM2;
        SM2->next = SM1;
        cout << "SM1.use_count() = " << SM1.use_count() << endl; */

        // multithreading
        /* thread t1(addNumbers, 20, 25);
        t1.join();
        thread t2(diffNumbers, 25, 20);
        t2.join(); */

        // race condition
        /* thread t1(increasebalance, 200);
        thread t2(increasebalance, 500);
        t1.join();
        t2.join(); */

        // singleton class
        Singleton *s1 = Singleton::getInstance();
        Singleton *s2 = Singleton::getInstance();
        if (s1 == s2)
        {
            cout << "same instance" << endl;
        }
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "e.what() = " << e.what() << '\n';
    }
}