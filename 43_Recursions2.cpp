#include <iostream>
#include <vector>
using namespace std;

// fibonacci
// check video for derivation
// TC for fibonacci recursive code = (2^n - 1) ~ 0((1.618)^n)
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// check array sorted
// 0(n)
bool isArraySorted(vector<int> &v, int n)
{
    if (n == 0)
        return true;
    return v[n] >= v[n - 1] && isArraySorted(v, n - 1);
}

// Q-704
//  reursive binary search
// TC - 0(logn) , SC - 0(logn) 
int searchTargetIndex(vector<int> &v, int tar, int st, int end)
{
    if (st <= end)
    {
        int mid = (st + end) / 2;
        if (v[mid] == tar)
            return mid;
        else if (v[mid] > tar)
        {
            end = mid - 1;
            return searchTargetIndex(v, tar, st, end);
        }
        else if (v[mid] < tar)
        {
            st = mid + 1;
            return searchTargetIndex(v, tar, st, end);
        }
    }
    return -1;
}

int main()
{
    // cout << fib(6);

    // vector<int> v = {1, 2, 3, 8, 5};
    // cout << isArraySorted(v, v.size());

    vector<int> v = {-1, 0, 3, 5, 9, 12};
    int tar = 50;
    cout << searchTargetIndex(v, tar, 0, v.size() - 1);
    return 0;
}