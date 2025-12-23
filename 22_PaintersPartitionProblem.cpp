#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 0(n)
bool isPossible(vector<int> &v, int n, int m, int maxAllocatedTime)
{
    int painters = 1;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time + v[i] <= maxAllocatedTime)
        {
            time += v[i];
        }
        else
        {
            painters++;
            time = v[i];
        }
    }
    return painters <= m;
}
// not understood - check another video
// Q -  https://www.naukri.com/code360/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

// 0(log(sum)*(n))  =
int minTimeToPaint(vector<int> &v, int n, int m)
{
    int sum = 0;
    int maxValue = INT_MIN;
    int ans = -1;
    for (int i = 0; i < n; i++) // 0(n)
    {
        sum += v[i];
        maxValue = max(v[i], maxValue);
    }
    int st = maxValue;
    int end = sum;
    while (st <= end) // 0(log(sum))
    {
        int mid = st + (end - st) / 2;
        if (isPossible(v, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    // int n = v.size();
    vector<int> v1 = {10, 20, 30, 40};
    int n = v1.size();
    int m = 2;
    // cout << "Min time required to paint the borads are " << minTimeToPaint(v, n, m) << endl;
    cout << "Min time required to paint the borads are " << minTimeToPaint(v1, n, m) << endl;
    return 0;
}
