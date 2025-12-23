#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// leetcode Q - 15
void print2dVector(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "}";
    }
}

// TC - 0(n3 * log(n))
// gives - TLE
vector<vector<int>> threeSum(vector<int> &v)
{
    vector<vector<int>> ans;
    set<vector<int>> s; // store unique triplets
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                if ((v[i] + v[j] + v[k] == 0))
                {
                    vector<int> trip = {v[i], v[j], v[k]};
                    sort(trip.begin(), trip.end());
                    // TC - logn (ordered set TC -> logn , unordered set TC -> 0(1))
                    if (s.find(trip) == s.end())
                    {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    print2dVector(ans);
    return ans;
}

// appraoch with hashing
// TC - 0(n2 * log(n))
////gives - TLE
vector<vector<int>> threeSum2(vector<int> &v)
{

    set<vector<int>> uniqueTriplets;
    for (int i = 0; i < v.size(); i++)
    {
        int target = -v[i];
        set<int> s;
        for (int j = i + 1; j < v.size(); j++)
        {
            int third = target - v[j];
            if (s.find(third) != s.end())
            {
                vector<int> trip = {v[i], v[j], third};
                sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip);
            }
            s.insert(v[j]);
        }
    }
    vector<vector<int>> ans{uniqueTriplets.begin(), uniqueTriplets.end()};
    print2dVector(ans);
    return ans;
}

// two pointer appraoch
// TC - 0(nlog(n) + n2))
vector<vector<int>> threeSum3(vector<int> &v)
{
    vector<vector<int>> ans;
    // nlog(n)
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        int j = i + 1;
        int k = v.size() - 1;
        while (j < k)
        {
            int sum = v[i] + v[j] + v[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                ans.push_back({v[i], v[j], v[k]});
                j++;
                k--;
                while (j < k && v[j] == v[j - 1])
                {
                    j++;
                }
            }
        }
    }
    print2dVector(ans);
    return ans;
}




int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    // threeSum(v);
    // threeSum2(v);
    threeSum3(v);

    return 0;
}