#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// leetcode 18 - 4sum

void printVector(vector<int> &v)
{
    for (int i = 0; i <= v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
}

// brute force
void fourSum(vector<int> &v, int tar)
{
    set<vector<int>> s;
    vector<int> quad;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                for (int l = k + 1; l < v.size(); l++)
                {
                    if (v[i] + v[j] + v[k] + v[l] == tar)
                    {
                        quad = {v[i], v[j], v[k], v[l]};
                        s.insert(quad);
                    }
                }
            }
        }
    }
    for (vector<int> v : s)
    {
        printVector(v);
    }
}

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

//TC - 0*(nlogn+n3)
void fourSum2(vector<int> &v, int tar)
{
    // set<vector<int>> s;
    vector<vector<int>> quad;
    //nlog(n)
    sort(v.begin(), v.end());
    //n3
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        for (int j = i + 1; j < v.size();)
        {

            int k = j + 1, l = v.size() - 1;
            while (k < l)
            {
                int sum = v[i] + v[j] + v[k] + v[l];
                if (sum == tar)
                {
                    quad.push_back({v[i], v[j], v[k], v[l]});
                    // s.insert(quad);
                    k++;
                    l--;
                    while (k < l && v[k] == v[k - 1])
                    {
                        k++;
                    }
                }
                else if (sum > tar)
                {
                    l--;
                }
                else if (sum < tar)
                {
                    k++;
                }
            }
            j++;
            while (j < v.size() && v[j] == v[j - 1])
                j++;
        }
    }
    
    print2dVector(quad);
}

int main()
{
    vector<int> v = {-2, -1, -1, 1, 1, 2, 2};
    int tar = 0;
    // fourSum(v, tar);
    fourSum2(v, tar);
    return 0;
}
