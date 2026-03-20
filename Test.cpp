#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <thread>
#include <mutex>
using namespace std;

vector<int> removeDuplicates(vector<int> &v)
{
    vector<int> ans;
    unordered_set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }

    for (int i : s)
    {
        ans.push_back(i);
    }

    return ans;
}

bool checkDuplicate(vector<int> &v, int n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (n == v[i])
            return true;
    }
    return false;
}

vector<int> removeDuplicates2(vector<int> &v)
{
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (!checkDuplicate(ans, v[i]))
        {
            ans.push_back(v[i]);
        }
    }

    return ans;
}

vector<int> removeDuplicates3(vector<int> &v)
{
    vector<int> ans;
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] != v[i])
        {
            ans.push_back(v[i - 1]);
        }
    }
    if (v[v.size() - 1] != v[v.size() - 2])
        ans.push_back(v[v.size() - 1]);

    return ans;
}
template <class T>
void add(T a, T b)
{
    cout << a + b << endl;
}

void swapPointer(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

class Test
{
public:
    Test() { cout << "constructor " << endl; }
    ~Test() { cout << "destructor " << endl; }
    // shared_ptr<Test> next;
    weak_ptr<Test> next;
};

mutex m;
int balance = 0;

void addBalance(int value)
{
    // m.lock();
    lock_guard<mutex> lock(m);
    balance += value;
    cout << "balance is " << balance << endl;
    // m.unlock();
}

mutex m1, m2;
void addBalance2(int value)
{

    m1.lock();
    balance += value;
    this_thread::sleep_for(1000ms);
    m2.lock();
    cout << "balance is " << balance << endl;
    m1.unlock();
    m2.unlock();
}

void addBalance3(int value)
{

    m2.lock();
    balance += value;
    this_thread::sleep_for(1000ms);
    m1.lock();
    cout << "balance is " << balance << endl;
    m1.unlock();
    m2.unlock();
}

int main()
{
    vector<int> v = {23, 24, 56, 67, 23, 45, 23, 78, 67, 23, 24};
    // vector<int> ans = removeDuplicates(v);
    // vector<int> ans = removeDuplicates2(v);
    // vector<int> ans = removeDuplicates3(v);
    // for (int i : ans)
    // {
    //     cout << i << " ";
    // }
    int *p = nullptr;
    // cout << "p = "<<p << endl;
    // cout << "*p = "<<*p << endl; //error-segmentation fault
    // add(5,5);

    /* int a = 45, b = 23;
    int *l = &a,*m=&b;
    swapPointer(&a, &b);  //swapping using pointers
    swapPointer(l, m);  //swapping using pointers  */

    /* shared_ptr<Test> t1 = make_shared<Test>();
    auto t2 =  make_shared<Test>();
    t1->next = t2;
    t2->next = t1;
    weak_ptr<Test> wk = t1; //memory leak when uncmommented sharedpointer in Test class since count is 2
    cout<<endl<<wk.use_count()<<endl; */

    /* unique_ptr<int[]> x = make_unique<int[]>(5);
    for(int i=0; i<5;i++){
        x[i] = (i+1)*10;
    }
    for(int i=0; i<5;i++){
        cout<<x[i]<<" ";
    }
 */

    // race condition and thread locking
    /* thread t1(addBalance, 1000);
    thread t2(addBalance, 1000);
    t1.join();
    t2.join(); */

    thread t1(addBalance2, 1000);
    thread t2(addBalance3, 1000);
    t1.join();
    t2.join();

    return 0;
}
