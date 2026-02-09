#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
mutex mtx;
void function1()
{
    cout << "Called by thread t1" << endl;
}
void function2()
{
    cout << "Called by thread t2" << endl;
}

void addNum(int x, int y)
{
    cout << "Addition is " << x + y << endl;
}
void mulNum(int x, int y)
{
    cout << "Multiplication is " << x * y << endl;
}

void addInfiniteNum1()
{
    int count = 0;
    for (long int i = 0; i < 100000000; i++)
    {
        count++;
    }
}

void addInfiniteNum2()
{
    int count = 0;
    for (long int i = 0; i < 100000000; i++)
    {
        count++;
    }
}

int sharedVarible = 0;
void sampleThread()
{

    cout << "sharedVarible = " << sharedVarible << endl;
    sharedVarible++;
}

int balance = 1000;
void addBalance(int amount)
{
    balance += amount;
    cout << "balance = " << balance << endl;
}

void addBalanceWithMutex(int amount)
{
    // check the header file for mutex and its initialization

    mtx.lock();
    balance += amount;
    cout << "balance = " << balance << endl;
    mtx.unlock();
}

mutex m1, m2;
void function1DeadLock()
{
    m1.lock();
    cout << "Executed funciton1 by thread1 " << this_thread::get_id() << endl;
    m2.lock();
    cout << "Crticical section from funtion1" << endl;
    m1.unlock();
    m2.unlock();
}
void function2DeadLock()
{
    m2.lock();
    cout << "Executed funciton2 by thread2 " << this_thread::get_id() << endl;
    m1.lock();
    cout << "Crticical section from funtion2" << endl;
    m2.unlock();
    m1.unlock();
}

void function1AvoidDeadLock()
{
    m1.lock();
    cout << "Executed funciton1 by thread1 " << this_thread::get_id() << endl;
    m2.lock();
    cout << "Crticical section from funtion1" << endl;
    m1.unlock();
    m2.unlock();
}
void function2AvoidDeadLock()
{
    m1.lock();
    cout << "Executed funciton2 by thread2 " << this_thread::get_id() << endl;
    m2.lock();
    cout << "Crticical section from funtion2" << endl;
    m1.unlock();
    m2.unlock();
}

int main()
{
    // check one note notes for multithreading

    // video 6
    /* cout<<"Main started "<<endl;
    thread t1(function1);
    thread t2(function2);
    t1.join();
    t2.join();
    cout<<"Main Ended "<<endl;
    //output
    //Main started 
    // Called by thread t2
    // Called by thread t1
    // Main Ended  */

    // video 7 - passing parameters to thread
    /* int x = 5, y = 10;
    cout << "Main started " << endl;
    thread t1(addNum, x, y);
    thread t2(mulNum, x, y);
    t1.join();
    t2.join();

    cout << "Main Ended " << endl;

    // output-> because of context switching
    // Main started
    // Addition is Multiplication is 15
    // 50
    // Main Ended */

    // video - 9 ->  Time taken by Multithreaded Execution vs Sequential Execution
    /* chrono::time_point<chrono::system_clock> start_time, end_time;
    start_time = chrono::system_clock::now();
    addInfiniteNum1();
    addInfiniteNum2();
    end_time = chrono::system_clock::now();
    cout << "Time taken by sequential execution " << (end_time - start_time).count() << endl;

    start_time = chrono::system_clock::now();
    thread t1(addInfiniteNum1);
    thread t2(addInfiniteNum2);
    end_time = chrono::system_clock::now();
    t1.join();
    t2.join();
    cout << "Time taken by multithreading execution " << (end_time - start_time).count() << endl;
    //output
    // Time taken by sequential execution 232154800
    // Time taken by multithreading execution 996900 */

    // video 10 -> Practical implementation of critical section problem using c++ || multithreading for HFT systems
    /* thread T[5];
    int size = sizeof(T) / sizeof(T[0]);
    // issue
    // for (int i = 0; i < size; i++)
    // {
    //     T[i] = thread(&sampleThread);
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     T[i].join();
    // }

    //output
    // sharedVarible = sharedVarible = 00
    // sharedVarible = sharedVarible = 1
    // 1
    // sharedVarible = 3

    // fix it like this`
    for (int i = 0; i < size; i++)
    {
        T[i] = thread(&sampleThread);
        cout << "thread number " << i << endl;
        T[i].join();
    } 
    //output 
    //thread number 1
    //sharedVarible = 1
    //thread number 2
    //sharedVarible = 2
    //thread number 3
    //sharedVarible = 3
    //thread number 4
    //sharedVarible = 4
    */

    // video 11-> critical section or race contition //check snap in one note
    //  video 12 -> mutex -> to avoid critical sectio problems
    // without mutex
    /* thread t1(addBalance, 200);
    thread t2(addBalance, 400);
    t1.join();
    t2.join();

    // output -> balance = balance = 16001600 */

    // with mutex
    /*  thread t1(addBalanceWithMutex, 200);
     thread t2(addBalanceWithMutex, 400);
     t1.join();
     t2.join();

     // //output
     // balance = 1200
     // balance = 1600 */

    // video 13 -> Solving a problem statement based on thread-queue and thread-executor class using c++

    // video 14 -> Multithreading: Multiple Mutex, Deadlock and Avoidance Technique!
    // Deadlock example
    /* thread t1(function1DeadLock);
    thread t2(function2DeadLock);
    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();
    // output ->Executed funciton1 by thread1Executed funciton2 by thread232
    // i.e. -> critical sction did not print in the output because of deadlock */

    // Deadlock solution
    /* thread t1(function1AvoidDeadLock);
    thread t2(function2AvoidDeadLock);
    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();
    //output
    // Executed funciton1 by thread1 2
    // Crticical section from funtion1
    // Executed funciton2 by thread2 3
    // Crticical section from funtion2 */

    // video 16 -> In depth exploration of different types of mutexes in c++
    //check from chatgpt
    /* 1. mutex
    2. recursive_mutex
    3. timed_mutex
    4. recursive_timed mutex
    5. shared_mutex
    6. shared_timed_mutex */

    return 0;
}