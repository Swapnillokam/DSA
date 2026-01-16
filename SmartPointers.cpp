#include <iostream>
#include <memory>

using namespace std;

class Wrapper
{
private:
    int *a;

public:
    Wrapper(int *a) : a(a)
    {
        cout << "constructor\n";
    }
    ~Wrapper()
    {
        cout << "destructor\n";
        delete a;
    }
};

// Shared Pointer
// //gives warning
// int *issueWithgetValue()
// {
//     int a = 5;
//     return &a;
// }

// works correctly but need to delete externally with delete operator
int *rawPointersGetValue()
{
    int *a = new int(5);
    return a;
}

shared_ptr<int> sharedPointersGetValue()
{
    shared_ptr<int> a = make_shared<int>(5);
    return a;
}

unique_ptr<int> uniquePointersGetValue()
{
    unique_ptr<int> a = make_unique<int>(5);
    return a;
}

// weak pointer
class Test
{
public:
    Test() { cout << "construtor called" << endl; }
    ~Test() { cout << "desstrutor called" << endl; }
    // for circular dependancy issue in shared pointer
    // shared_ptr<Test> next;
    weak_ptr<Test> next;
};

int main()
{
    /* int *a = new int(10);
    cout << *a;
    delete a;
    a = nullptr;
    cout << *a; */

    // RAII
    /* Wrapper obj(new int(10));
    return 0; */

    // //gives warning
    /* int *c = issueWithgetValue();
    cout << *c << endl;
    cout << *c << endl;
    cout << *c << endl;
    cout << *c << endl; */

    // // raw pointers- works correctly but need to delete externally with delete operator
    /* int *d = rawPointersGetValue();
    cout << *d << endl;
    cout << *d << endl;
    delete d;
    cout << *d << endl;  // gives garbage value since d is deleted and not null
    cout << *d << endl; // gives garbage value since d is deleted and not null */

    // // shared Pointer -> no need to delete deletes automatically once the variable goes out of the scope
    /* shared_ptr<int> e = sharedPointersGetValue(); // or
    // auto e = sharedPointersGetValue();
    cout << *e << endl;
    cout << *e << endl;
    auto f = e;
    cout << *f << endl;
    cout << e.use_count() << endl; // no.of pointers pointing to the same address
    cout << f.use_count() << endl; // no.of pointers pointing to the same address
    weak_ptr<int> k = e;
    cout << k.use_count() << endl; // // weak pointer does not take ownership of object but it simple observes
                                   // weak pointers does not involved in the count its just the reference to the memory but shared
 */

    // unique Pointer -> no need to delete deletes automatically once the variable goes out of the scope
    /* unique_ptr<int> g = uniquePointersGetValue();  //or
    // auto e = sharedPointersGetValue();
    cout << *g << endl;
    cout << *g << endl;
    // auto h = g;   // not possible
    auto h = move(g);   // moving hte pointer and hence g pointer is moved to h and g is not holding any pointer
    cout << *h << endl;
    cout << *g << endl;  // check g */

    // weak pointer
    /* shared_ptr<Test> t1(new Test());
    // shared_ptr<Test> t1 = new Test();  // wrong syntax
    shared_ptr<Test> t2 = t1; // or
    // shared_ptr<Test> t2(t1);
    cout << t1.use_count() << endl;
    weak_ptr<Test> w1 = t1;
    cout << w1.use_count() << endl;
    auto ptr = w1.lock(); // lock() retuens a refernce to shared pointer // you can also use expired() returns boolean
    if (ptr)
    {
        cout << "weak pointer exists" << endl; // called before destructor
    }
    t1.reset();
    ptr.reset();
    cout << w1.use_count() << endl;
    cout << t1.use_count() << endl;
    auto ptr2 = w1.lock();
    if (!ptr2)
    {
        cout << "ptr2 is deleted" << endl;
    } */

    // shared pointer circular dependancy issue
    shared_ptr<Test> t1(new Test);
    shared_ptr<Test> t2(new Test);
    t1->next = t2;
    t2->next = t1;
    cout << " t1.use_count() = " << t1.use_count() << endl;
    cout << " t2.use_count() = " << t2.use_count() << endl;
    //issue -> (uncomment shared pointer in class and commed weak pointer)note run the program and check destructor never gets called, hence memory leak
    //create the weak pointer in class for next object
    return 0;
}