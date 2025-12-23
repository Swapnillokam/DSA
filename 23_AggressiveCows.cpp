#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &v, int n, int m, int minAllowedDistance)
{
    int cows = 1;
    int lastStallPos = v[0];
    for (int i = 0; i < n; i++)
    {   int diff = v[i] - lastStallPos;
        if (v[i] - lastStallPos >= minAllowedDistance)
        {
            cows++;
            lastStallPos = v[i];
        }
        if (cows == m)
        {
            return true;
        }
    }
    return false;
}
int getDistance(vector<int> &v, int n, int m)
{
    // int maxValue = INT_MIN;
    // int minValue = INT_MAX;
    // for (int i = 0; i < n; i++)
    // {
    //     maxValue = max(v[i], maxValue);
    //     minValue = min(v[i], minValue);
    // }
    sort(v.begin(), v.end());

    int ans = -1;
    int st = 1;
    int end = v[n - 1] - v[0];
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(v, n, m, mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 8, 4, 9};
    int n = v.size();
    int m = 3;
    cout << "The min distanec between the stall should be " << getDistance(v, n, m) << endl;
    return 0;
}
