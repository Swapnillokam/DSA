#include <iostream>
#include <vector>
using namespace std;

bool searchInMatrix(vector<vector<int>> &v, int tar, int row)
{
    int n = v[0].size();
    int st = 0, end = n - 1;
    while (st <= end)
    {
        int mid = (st + mid) / 2;
        if (v[row][mid] == tar)
        {
            return true;
        }
        else if (v[row][mid] < tar)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

// leetcode Q-74
// TC - 0(log (n * m))
bool searchIn2DMatrix(vector<vector<int>> &v, int tar)
{
    int m = v.size(); // gives no.of rows
    int n = v[0].size();
    int stRow = 0, endRow = n - 1;
    while (stRow <= endRow)
    {
        int midRow = (stRow + endRow) / 2;
        if (v[midRow][0] <= tar && v[midRow][n - 1] >= tar)
        {
            return searchInMatrix(v, tar, midRow);
        }
        else if (tar > v[midRow][n - 1])
        {
            stRow = midRow + 1;
        }
        else
        {
            endRow = midRow - 1;
        }
    }
    return false;
}

// leetcode - 240
// 0(m*n)
bool searchIn2DMatrix_2(vector<vector<int>> &v, int tar)
{
    int m = v.size();
    int n = v[0].size();

    int rows = 0;
    int column = n - 1;

    while (rows < m && column >= 0)
    {
        if (v[rows][column] == tar)
        {
            return true;
        }
        else if (v[rows][column] > tar)
        {
            column--;
        }
        else
        {
            rows++;
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> v = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 34;
    // cout << searchIn2DMatrix(v, target);

    vector<vector<int>> v1 = {
        {{1, 4, 7, 11, 15},
         {2, 5, 8, 12, 19},
         {3, 6, 9, 16, 22},
         {10, 13, 14, 17, 24},
         {18, 21, 23, 26, 30}}};
    int target1 = 5;
    cout << searchIn2DMatrix_2(v1, target1);
    return 0;
}