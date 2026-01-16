#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void pointersStringsAndChar()
{
    // pointers knowledge for chararcter[],string,int array[]
    int arr[] = {1, 2, 3, 4};
    int *p = arr;

    cout << endl
         << "Expected Behaviour for Integer arrays" << endl;

    cout << "arr = " << arr << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "*(p + 1) = " << *(p + 1) << endl;
    cout << "*p + 1 = " << *p + 1 << endl;

    cout << endl
         << "Behaviour for string and char arrays" << endl;
    string x = "abc";
    char *c = "asdbuha";
    char d[] = {'x', 'c', 'f'};
    char *e = d;

    cout << endl
         << "x related = " << endl;
    cout << "x = " << x << endl;

    cout << endl
         << "c related = " << endl;
    cout << "c = " << c << endl;
    cout << "*c = " << *c << endl;

    cout << endl
         << "d related = " << endl;
    cout << "d = " << d << endl; //-> different bevaviour for char[]
    cout << "(void *)d = " << (void *)d << endl;
    cout << "&d = " << &d << endl;
    cout << "*d = " << *d << endl;

    cout << endl
         << "e related = " << endl;
    cout << "e = " << e << endl;
    cout << "(void *)e = " << (void *)e << endl;
    cout << "&e = " << &e << endl;
    cout << "*e = " << *e << endl;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // cout << "v[" << i << "]=" << v[i] << endl;
        cout << v[i] << " ";
    }
    cout << endl;
}
void vectors()
{
    // vector<int>vec = {1,2};
    // printVector(vec);
    // vector<int>vec(3,0);  //(size,values)
    // printVector(vec);
    // vector<int>vec2(vec);
    // printVector(vec);

    vector<int> v;
    // v.push_back(1);
    // // v.push_back(1);
    // // v.push_back(1);
    // // // v.push_back(1);
    // // // // v.push_back(1);
    // cout << "size =" << v.size() << endl;
    // cout << "capacity =" << v.capacity() << endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // // printVector(v);
    // // v.pop_back();
    // // printVector(v);
    // // v.emplace_back(6);
    // // printVector(v);

    // cout<<"v[2]="<<v[2]<<" v.at(2) "<<v.at(2)<<endl;
    // cout<<"v.front()="<<v.front()<<" v.back()="<<v.back()<<endl;

    // printVector(v);
    // v.erase(v.begin(),v.begin()+2);
    // printVector(v);
    // v.erase(v.begin(),v.end());
    // printVector(v);

    // v.insert(v.begin() + 2, 100);  //insert(index,value)
    // // cout << v.empty() << endl;
    // // printVector(v);
    // // v.clear();
    // // printVector(v);
    // // cout << v.empty() << endl;
    // printVector(v);

    // printVector(v);
    // cout << "*(v.begin() )=" << *(v.begin()) << endl;
    // cout << "*(v.end() )=" << *(v.end()) << endl;
    // cout << "*(v.end()-1 )=" << *(v.end()-1) << endl;
    // printVector(v);
    // vector<int>::iterator it;
    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //    cout<<*(it)<<" ";
    // }
    // for (auto it = v.rbegin(); it != v.rend(); it++)
    // {
    //     cout<<*(it)<<" ";
    // }

    // vector<int>::reverse_iterator it1;  //not undderstood the use of "reverse_iterator it1" since it is behaving same as "iterator it"
    // for (auto it1 = v.rbegin(); it1 != v.rend(); it1++)
    // {
    //     cout << *(it1) << " ";
    // }
    // for (auto it1 = v.begin(); it1 != v.end(); it1++)
    // {
    //     cout << *(it1) << " ";
    // }
}

void printList(list<int> &l)
{
    // for (int i = 0; i < l.size(); i++)
    // {
    //     cout << l.<< " "; // gives error
    // }

    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}
void List()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.emplace_back(3);
    l.emplace_front(4);

    l.pop_back();
    l.pop_front();
    printList(l);

    // iterrator operations are used in list
    //  list<int>::iterator it;
    //  v[i]  //gives error , since memory in list is not stored in contageous manner

    cout << endl;
}

void deque()
{
    // some as list
    //  but v[i] is possible
}

void Pair()
{
    // pair<string, int> p = {"Swapnil:", 1};
    // cout << "p.first = " << p.first << endl;
    // cout << "p.second = " << p.second << endl;

    // pair<int, pair<char, int>> p = {1, {'S', 10}};
    // cout << "p.first = " << p.first << endl;
    // cout << "p.second.first = " << p.second.first << endl;
    // cout << "p.second.second = " << p.second.second << endl;
}

void printMap(map<string, int> &m)
{
    for (auto p : m)
    {
        cout << p.first << " : " << p.second << endl;
    }
    cout << endl;
}
void Maps()
{
    map<string, int> m;
    m["tv"] = 100;
    m["laptop"] = 5;
    m["Headpnoes"] = 2;
    // cout << m["tv"] << endl;
    // printMap(m);
    // cout << m.find("tv"); //gives errro iterator concept

    // if (m.find("tv") != m.end())
    // {
    //     cout << "found" << endl;
    // }
    // else
    //     cout << "found" << endl;

    // with iterator
    // map<string, int>::iterator it;
    // for (it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " : " << it->second << endl;
    // }
    // if (it = m.find("tv") != it = m.end()) //-> gives error
    // {
    //     cout << "found" << endl;
    // }
    // else
    //     cout << "found" << endl;

    for (auto map : m)
    {
        cout << map.first << " : " << map.second << endl;
    }
}

void Sets()
{
    set<int> s;

    s.insert(5);
    s.insert(3);
    s.insert(5);

    for (auto set : s)
    {
        cout << set << " ";
    }

    if (s.find(5) != s.end())
    {
        cout << "found" << endl;
    }
}

void CPP_STL()
{
    // vectors
    // vectors();
    // List();
    // deque();
    // Pair();
    // Maps();
    // Sets();
}

int foo() { return 10; }
void functionPointers()
{
    // function pointer → points to foo
    int (*fp)() = foo;

    cout << "fp = " << fp << endl;
    cout << "foo = " << foo << endl;
}

template <class T>
class Arithmetic
{
    T a, b;

public:
    Arithmetic(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    void add()
    {
        cout << "sum is " << this->a + this->b << endl;
    }
};

void Map()
{
    map<string, int> map;
    map["Swapnil"] = 20;
    map["Rahul"] = 30;
    map["Sneha"] = 40;

    map["Swapnil"] = 40;

    map.insert({{"lokam", 50}, {"sbhks", 40}});

    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second << endl;
    }

    cout << map.empty() << endl;
    cout << map.size() << endl;
    // cout << map.count() << endl;
    cout << map.erase("sbhks") << endl;
    if (map.find("Swapnil") != map.end())
    {
        map.erase(map.find("Swapnil"));
    }

    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second << endl;
    }

    auto it = map.find("Rahul");

    cout << (*it).first << " : " << (*it).second << endl;
}

void Set()
{
    set<int> marks = {12, 32, 12, 23, 43};
    marks.insert(42);

    for (auto it = marks.begin(); it != marks.end(); it++)
    {
        cout << (*it) << " " << endl;
    }
    cout << marks.erase(42) << endl;
    for (auto it = marks.begin(); it != marks.end(); it++)
    {
        cout << (*it) << " " << endl;
    }

    auto it = marks.find(12);
    cout << endl;
    cout << (*it) << endl;

    // marks.erase();
}

int main()
{
    pointersStringsAndChar();
    // CPP_STL();
    // functionPointers();

    // Template
    //  Arithmetic<float> A(2.5, 3.8);
    //  A.add();

    // one more
    // Map();
    // Set();
    return 0;
}