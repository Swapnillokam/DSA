#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
    Singleton() {}
    static Singleton *instance;
    static mutex mtx;
public:
    static Singleton *getInstance()
    {
        lock_guard<mutex> lock(mtx);
        if (instance == nullptr)
            instance = new Singleton();
        return instance;
    }

    Singleton(const Singleton &other) = delete;
    Singleton& operator=(const Singleton &other) = delete;
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    if (s1 == s2)
    {
        cout << "Same" << endl;
    }
    return 0;
}