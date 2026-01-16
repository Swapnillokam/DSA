#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// Daemon thread
void Daemon()
{
    while (1)
    {
        cout << "I am daemon thread. No one can kill me except the process is terminated" << endl;
        this_thread::sleep_for(1000ms);
    }
}

// Move thread ownership -> Moving a thread (not copying)
//  two instances of the same thread is not possible hence copying is notpsosible you have to mmove jthe thread
void worker(int number)
{
    cout << "I am a worker thread numebr : " << number << endl;
}

void hello()
{
    cout << "actual thread adn its id : " << this_thread::get_id() << endl;
    // inside a a existing thread -> use this_thread::get_id()
    //  on the main use -> thread::get_id()
}

void listen_for_shortcut_key(stop_token tk)
{
    while (1)
    {
        cout << "I am listening for key pressed" << endl;
        if (tk.stop_requested())
        {
            cout << "Stop requsted" << endl;
            return;
        }
        this_thread::sleep_for(1000ms);
    }
}

// check video no 12
binary_semaphore
    smphsignalMainToThread{0},
    smphsignalThreadToMain{0};

// only 0 and 1 are allowed -> binary semaphore

void ThreadProc()
{
    smphsignalMainToThread.acquire();
    // acquire -> decrements 1 -> 0

    cout << "[thread] got hte signal" << endl;

    this_thread::sleep_for(3s);

    cout << "[thread] Send hte signal" << endl;

    smphsignalThreadToMain.release();
    // release -> increments  0 -> 1
}

int counter = 0;
mutex m;
void run()
{
    m.lock();
    for (int i = 0; i < 100000; i++)
    {
        counter++;
    }
    m.unlock();
}

#define buff_size 5
int buff[buff_size];

binary_semaphore
    signal_to_producer{1},
    signal_to_consumer{0};

void producer()
{
    while (1)
    {
        signal_to_producer.acquire();
        cout << "Produced : ";
        for (int i = 0; i < buff_size; i++)
        {
            buff[i] = i * i;
            cout << buff[i] << " " << flush;
            this_thread::sleep_for(200ms);
        }
        cout << endl;
        signal_to_consumer.release();
    }
}

void consumer()
{
    while (1)
    {
        signal_to_consumer.acquire();
        cout << "Consumed : ";
        for (int i = buff_size - 1; i >= 0; i--)
        {
            cout << buff[i] << " " << flush;
            buff[i] = 0;
            this_thread::sleep_for(200ms);
        }
        cout << endl
             << endl;
        signal_to_producer.release();
    }
}

// atomic varables
atomic<int> counter2 = 0;
// avoids the race condition
//  no need to use lock and unlock mechanismm
void run2()
{
    for (int i = 0; i < 100000; i++)
    {
        counter2++;
    }
}
int main()
{
    // 1.  Daemon
    /* thread t1(Daemon);
    //running in the background
    t1.detach();
    this_thread::sleep_for(5000ms); //may be main thread*/

    // 2. moving thread ownership
    /* vector<thread> workers;
    for (int i = 0; i < 10; i++)
    {
        thread t(worker, i);
        // workers.push_back(t);  // gives error that thread cannot be copied
        workers.push_back(move(t));  //or emplace_back instead of move
        // workers.emplace_back(t);
    }

    // for (auto it = workers.begin(); it != workers.end(); it++)
    // {
    //     (*it).join();
    //     // prints the differnt o/p on evrey run
    // }
    // or
    for (int i = 0; i < workers.size(); i++)
    {
        workers[i].join();
        // prints the differnt o/p on evrey run
    } */

    // 3. No.of threads at runtime -> no.of cores/processors in the system -> no.of concurrent threads possible (using hardware_concurrency() function)
    /* vector<thread> workers;
    unsigned long const hardware_threads = thread::hardware_concurrency();
    cout << "no.og cores/processors - " << hardware_threads << endl;
    for (int i = 0; i < 10; i++)
    {
        // thread t(worker, i);
        // workers.emplace_back(t);  //gives error
        workers.emplace_back(worker,i);
        //difficult to understand the syntzx you can use the previous loop only
    }

    for (auto it = workers.begin(); it != workers.end(); it++)
    {
        (*it).join();
        // prints the differnt o/p on evrey run
    } */

    // 4. Identify threads at run time
    /*  thread t(hello);

     cout << "current new thread id in main : " << t.get_id() << endl;
     // inside a a existing thread -> use this_thread::get_id()
     //  on the main use -> thread::get_id()
     t.join(); */

    // 5. problems sharing data between threads
    // 6. solution -> race condition
    // jthread -> only in C++20  -> join thread -> joins automatically destructor is called once the thread goes out of scope
    /* {
        vector<jthread> workers;
        for (int i = 0; i < 10; i++)
        {
            jthread t(worker, i);
            // workers.push_back(t);  // gives error that thread cannot be copied
            workers.push_back(move(t)); // or emplace_back instead of move
            // workers.emplace_back(t);
        }
    } // addiing this extra scope so that threads are join automatically using jthread once the thread gos out of scope and main thread is continued, if oyu dont add the scope hello main can be printted at any random order

    cout << "hello main" << endl; */

    // jthread request_stop
    /*  jthread gui(listen_for_shortcut_key);
     this_thread::sleep_for(5000ms);
     gui.request_stop(); // confused, it works without request_stop() as well */

    // check video no 12
    // Binary semaphore //signalling or informing other threads about the status
    /*   thread tHworker(ThreadProc);
      cout << "[main] send hte signal" << endl;

      smphsignalMainToThread.release();
      // 0 -> 1

      smphsignalThreadToMain.acquire();

      cout << "[main] Got the signal" << endl;

      tHworker.join(); */

    // video no-> 15,race condition
    /* thread t1(run);
    thread t2(run);

    t1.join();
    t2.join();

    cout << counter << endl;
    // expected 200000 but actual is random numebr output
    //Hence the issue is solved using mutex -> check the code by commenting and uncomenting the lcok and unlock int he run function
    // Hence mutex stops other threads to be executed when already a thread is implementing the fucntion */

    // mutex or semaphore
    /* common - > both are synchronisation primitives

    mutex
    1. one thread
    2. lock/unlock mechanism
    3. Locking mechanism
    mutual exclusion -> ex in Race condition

    semaphore
    1. multiple thread
    2. Count
    3. Signalling mechanism
    limit the count of the thread for signalling
    */

    // producer comsumer wiht semaphore
    /*  thread producerThread(producer);
     thread consumerThread(consumer);

     cout << "[main] Got hte signal" << endl;

     producerThread.join();
     consumerThread.join(); */

    // thread pool -> no.of cores in the system
    // left the video -> complex

    // Atomic variables in CPP
    /* thread t1(run2);
    thread t2(run2);

    t1.join();
    t2.join();

    cout << counter2 << endl;
    // avoids the race condition
    // no need to use lock and unlock mechanismm 
    //avoids lock based program
    */

    //Thread Safe singleton class
    return 0;
}