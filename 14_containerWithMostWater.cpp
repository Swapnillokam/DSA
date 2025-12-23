#include <iostream>
#include <vector>
using namespace std;

// leetcode Q.11
// bruteforce appraoch - 0(n2)
int maxWater(vector<int> &vec)
{
    int maxwater = 0;
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int w = j - i;
            int h = min(vec[j], vec[i]);
            int curWater = w * h;
            maxwater = max(maxwater, curWater);
        }
    }
    return maxwater;
}

// Two pointer appraoch - 0(n)
int maxWater2(vector<int> &vec)
{
    int n = vec.size();
    int maxWater = 0;
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int w = right - left;
        int h = min(vec[left], vec[right]);
        int currWater = w * h;
        maxWater = max(maxWater, currWater);
        vec[left] < vec[right] ? left++ : right--;
    }
    return maxWater;
}

int main()
{
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // cout << "The max vol of water is " << maxWater(vec) << endl;
    cout << "The max vol of water is " << maxWater2(vec) << endl;
    return 0;
}

