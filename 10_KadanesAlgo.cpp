#include <iostream>
#include <climits>
using namespace std;

void subArray()
{
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    for (int st = 0; st < n; st++)
    {
        cout << "st - a[" << st << "] -> ";
        for (int end = st; end < n; end++)
        {
            // cout << "end - a[" << end << "] : ";
            for (int i = st; i <= end; i++)
            {
                cout << a[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

// question
// Brute force approach
// Maximum sub array sum
// leetcode 53
int maxSubarraySum()
{
    int a[] = {1, -4, 6, 3, 7, -10};
    // int a[] = {3, -4, 5, 4, -1, 7, -8};
    // int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int maxSum = INT_MIN;

    for (int st = 0; st < size; st++)
    {
        int currentSum = 0;
        for (int end = st; end < size; end++)
        {
            cout << a[end] << ",";
            currentSum += a[end];
            cout << "cSum=" << currentSum << ",";
            maxSum = max(currentSum, maxSum);
            cout << "mSum=" << maxSum << endl;
        }
        cout << endl;
        cout << endl;
    }
    return maxSum;
}

// most optimised
// kadane's algo
int maxSubarraySumByKadane()
{
    // int a[] = {1, -4, 6, 3, 7, -10};
    // int a[] = {3, -4, 5, 4, -1, 7, -8};
    int a[] = {-15, -4, -5, -4, -5, -2, -10, -8};
    // int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int st = 0; st < size; st++)
    {
        currentSum += a[st];
        maxSum = max(currentSum, maxSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main()
{

    // subArray();
    //  cout << "Max Subaaray Sum is " << maxSubarraySum();
    cout << "Max Subaaray Sum is " << maxSubarraySumByKadane();
    return 0;
}