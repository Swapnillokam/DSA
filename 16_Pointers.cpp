#include <iostream>
using namespace std;

void changeA(int a) // pass by value
{
    a = 20;
}
void changeAusingPointers(int *ptr) // pass by reference using pointers
{
    *ptr = 30;
}
void changeAusingAlias(int &b) // pass by reference using alias
{
    b = 40;
}

int main()
{
    // int a = 10;
    // int *p = &a;
    // cout << "&a = " << &a << endl;
    // cout << "p = " << p << endl;
    // cout << "*p = " << *p << endl;

    // int a = 10;
    // changeA(a);
    // cout << "a = " << a << endl;
    // changeAusingPointers(&a);
    // cout << "a = " << a << endl;
    // changeAusingAlias(a);
    // cout << "a = " << a << endl;

    // Arrray Pointers
    // int arr[] = {1, 2, 3, 4, 5};
    // cout << "arr = " << arr << endl;   //-->  0x61fefc
    // cout << "*arr = " << *arr << endl;  ////-->  1

    // int b = 15;
    // arr = &b;  //error - expression must be a modifiable lvalue

    // Pointer arithmetic
    // int a = 10;
    // int *p = &a;
    // cout << "p   = " << p << endl;
    // p++;
    // cout << "p++ = " << p << endl;
    // p--;
    // cout << "p-- = " << p << endl;
    return 0;
}