#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void print2DArrays()
{
    int a[3][3];
    cout << "Enter the array values" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "The array values are: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void _2DlinearSearch(int a[][3], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // cout << a[i][j] << " ";
            if (a[i][j] == target)
            {
                cout << "a[" << i << "][" << j << "]" << " = " << target << endl;
            }
        }
    }
}

void maxRowSum2D(int a[][3], int rows, int cols)
{
    int maxRowSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum = sum + a[i][j];
        }
        maxRowSum = max(maxRowSum, sum);
    }
    cout << "The max row sum is " << maxRowSum << endl;
}

void sumOfTwoElements2(vector<int> &v, int target)
{
    vector<int> ans;
    unordered_map<int, int> m;

    for (int i = 0; i < v.size(); i++)
    {
        int first = v[i];
        int sec = target - first;
        if (m.find(sec) != m.end())
        {
            ans.push_back(m[sec]);
            ans.push_back(i);
            break;
        }
        m[first] = i;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void findMissingAndRepeatingValues(vector<vector<int>> &v)
{
    set<int> s;
    vector<int> ans;
    int actualSum = 0, expectedSum = 0, a;
    int n = v.size();
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            actualSum += v[i][j];
            count++;
            if (s.find(v[i][j]) != s.end())
            {
                a = v[i][j];
                ans.push_back(v[i][j]);
            }
            s.insert(v[i][j]);
        }
    }
    expectedSum = count * (count + 1) / 2;
    cout << "count = " << count << endl;
    cout << "expectedSum = " << expectedSum << endl;
    cout << "actualSum = " << actualSum << endl;
    cout << "a = " << a << endl;
    int missingValue = expectedSum + a - actualSum;
    ans.push_back(missingValue);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void findDuplicate(vector<int> &v)
{
    set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.find(v[i]) != s.end())
            cout << "duplicate value = " << v[i];
        s.insert(v[i]);
    }
}
int main()
{
    // print2DArrays();
    int a[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};
    // _2DlinearSearch(a, 4, 3, 12);
    // maxRowSum2D(a, 4, 3);

    vector<int> v = {5, 2, 11, 7, 15};
    int target = 9;
    // sumOfTwoElements2(v, target);

    vector<vector<int>> v1 = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}};
    // findMissingAndRepeatingValues(v1);

    vector<int> v3 = {1, 3, 4, 2, 2};
    findDuplicate(v3);
    return 0;
}