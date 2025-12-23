#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// print sunsets of an arays
// No.of subsets = 2^n (n- size of hte array)
// TC = total calls x Work done in each call = 2^n*n x 0(1)
// SC =
void printSubArraysRecursive(vector<int> &v, vector<int> &ans, int n, int i)
{
    if (i == n)
    {
        for (int x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    // inclusion
    ans.push_back(v[i]);
    printSubArraysRecursive(v, ans, n, i + 1);

    ans.pop_back(); // backtrack
    // exclusion
    printSubArraysRecursive(v, ans, n, i + 1);
}

// Q - 78
// TC - 0(n*2^n)
void printAllSubsets(vector<int> &v, vector<int> &ans, int n, int i, vector<vector<int>> &allSubsets)
{
    if (i == n)
    {
        allSubsets.push_back(ans);
        return;
    }
    // inclusion
    ans.push_back(v[i]);
    printAllSubsets(v, ans, n, i + 1, allSubsets);

    ans.pop_back(); // backtrack
    // exclusion
    printAllSubsets(v, ans, n, i + 1, allSubsets);
}

// Q-90
//
void printAllSubsetsWithDuplicates(vector<int> &v, vector<int> &ans, int n, int i, vector<vector<int>> &allSubsets)
{
    if (i == n)
    {
        allSubsets.push_back(ans);
        return;
    }
    // inclusion
    ans.push_back(v[i]);
    printAllSubsetsWithDuplicates(v, ans, n, i + 1, allSubsets);

    ans.pop_back(); // backtrack
    int idx = i;
    while (idx < n and v[idx] == v[idx + 1])
    {
        idx++;
    }

    // exclusion
    printAllSubsetsWithDuplicates(v, ans, n, idx + 1, allSubsets);
}


int main()
{
    vector<int> v = {0, 1, 2};
    vector<int> ans;
    vector<vector<int>> allSubsets;

    printSubArraysRecursive(v, ans, v.size(), 0);
    // printAllSubsets(v, ans, v.size(), 0, allSubsets);
    // for (vector<int> i : allSubsets)
    // {
    //     for (int j : i)
    //     {
    //         cout << j;
    //     }
    //     cout << " ,";
    // }

    // vector<int> v1 = {1, 2, 2};
    // sort(v1.begin(),v1.end());
    // printAllSubsetsWithDuplicates(v1, ans, v1.size(), 0, allSubsets);
    // for (vector<int> i : allSubsets)
    // {
    //     for (int j : i)
    //     {
    //         cout << j;
    //     }
    //     cout << " ,";
    // }
    return 0;
}
