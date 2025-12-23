// Time complexity
/*
1. Recurrence Relation
f(n)=k + f(n-1)
f(n-1)=k + f(n-2)
f(n-2)=k + f(n-2)
f(n-3)=k + f(n-2)
.........
.........
.........
f(1)=k + f(0)(k2)
after summing all

f(n) = n*k + k2
TC = 0(n)

2. TC = total no.of recursion calls x work in each call
 */

// Space Complexity
/*
SC = Height of call stack * memory in each cell

SC = n*k
SC = 0(n)
 */

#include <iostream>

using namespace std;

// recursive function
void printNum(int n)
{
    if (n == 1)
    {
        cout << 1;
        return;
    }
    cout << n << " ";
    printNum(n - 1);
}

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

// sum of n numbers
int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}
int main()
{
    // printNum(5);
    // cout << fact(6);
    cout << sum(6);
    return 0;
}