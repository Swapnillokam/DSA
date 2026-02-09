#include <iostream>

using namespace std;

template <class T>
class Add
{
public:
    T a, b;
    Add(T x, T y) : a(x), b(y) {}
    void add()
    {
        cout << "sum is " << a + b << endl;
    }
};

int main()
{
    // Add a(5,6);
    // a.add();
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}