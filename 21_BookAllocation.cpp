#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &v, int n, int m, int maxAllocatedPages) // 0(n)
{
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > maxAllocatedPages)
        {
            return false;
        }
        if (pages + v[i] <= maxAllocatedPages)
        {
            pages += v[i];
        }
        else
        {
            students++;
            pages = v[i];
        }
    }
    return students > m ? false : true;
}

/// @brief
/// @param m = no.of studnets
/// @param n = no.of pages
/// @param v
/// @return
int allocateBooks(vector<int> &v, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    int ans = -1;
    int st = 0;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) // 0(n)
    {
        sum += v[i];
    }
    int end = sum; // no.of possible answers

    // bianry search
    while (st <= end) // 0(log(range of possible answers)) -> 0(log(n))
    {
        int mid = st + (end - st) / 2;
        if (isValid(v, n, m, mid)) // left
        {
            ans = mid;
            end = mid - 1;
        }
        else // right
        {
            st = mid + 1;
        }
    }
    return ans;
}
int main()
{
    // vector<int> v = {2, 1, 3, 4};
    vector<int> v1 = {15, 17, 20}; // 32
    int n = 4, m = 2;
    cout << "Minimum no.of pages to a student is " << allocateBooks(v1, n, m) << endl;
    return 0;
}