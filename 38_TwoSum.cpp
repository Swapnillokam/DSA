#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// aware about brute force appraoch - 0(n2)
//  better appraoch - 2 pointer approach - 0(nlog(n))
// leetcode q -1
bool sumOfTwoElements(vector<int> &v, int target)
{
    sort(v.begin(), v.end());
    int st = 0, end = v.size() - 1;
    while (st < end)
    {
        int sum = v[st] + v[end];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            st++;
        }
    }
    return false;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i <= v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
}
// 0(n)
vector<int> sumOfTwoElements2(vector<int> &v, int target)
{
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        int first = v[i];
        int sec = target - first;
        if (m.find(sec) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[first] = i;
    }
    printVector(ans);
    return ans;
}

// leetcode Q- 2965
// 0(n2)
vector<int> findMissingAndRepeatingValues(vector<vector<int>> &v)
{
    vector<int> ans;
    unordered_set<int> s;
    int expectedSum = 0, a, actualSum = 0, n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            actualSum += v[i][j];
            if (s.find(v[i][j]) != s.end())
            {
                a = v[i][j];
                ans.push_back(a);
            }
            s.insert(v[i][j]);
        }
    }
    expectedSum = (n * n) * (n * n + 1) / 2;
    int b = expectedSum + a - actualSum;
    ans.push_back(b);
    printVector(ans);
    return ans;
}

// leetcode - Q 287
//brte force
//TC - 0(n),SC - 0(n)
int findDuplicate(vector<int> &v)
{
    unordered_set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.find(v[i]) != s.end())
        {
            return v[i];
        }
        s.insert(v[i]);
    }

    return -1;
}

//slow and fast pointer appraoch
//not understood
int findDuplicate2()
{
    return -1;
}

int main()
{
    vector<int> v = {5, 2, 11, 7, 15};
    int target = 9;
    // cout << sumOfTwoElements(v, target);
    // sumOfTwoElements2(v, target);

    vector<vector<int>> v1 = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}};
    // findMissingAndRepeatingValues(v1);

    vector<int> v3 = {1, 3, 4, 2, 2};
    // cout<<"Duplicate value is "<<findDuplicate(v3)<<endl;
    return 0;
}