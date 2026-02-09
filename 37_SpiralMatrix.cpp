#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &v)
{
    int r = v.size();
    int c = v[0].size();
    int topRow = 0, leftCol = 0;
    int bottomROw = r - 1, rightCol = c - 1;
    vector<int> ans;
    while (topRow <= bottomROw && leftCol <= rightCol)
    {
        // top
        for (int i = leftCol; i <= rightCol; i++)
        {
            ans.push_back(v[topRow][i]);
        }
        // right
        for (int i = topRow + 1; i <= bottomROw; i++)
        {
            ans.push_back(v[i][rightCol]);
        }
        // bottom
        for (int i = rightCol - 1; i >= leftCol; i--)
        {
            if (topRow == bottomROw)
            {
                break;
            }
            ans.push_back(v[bottomROw][i]);
        }
        // left
        for (int i = bottomROw - 1; i >= topRow + 1; i--)
        {
            if (leftCol == rightCol)
            {
                break;
            }
            ans.push_back(v[i][leftCol]);
        }
        topRow++;
        rightCol--;
        bottomROw--;
        leftCol++;
    }
    return ans;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i <= v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
}
// leetcode - Q 54
int main()
{
    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    vector<int> newVec = spiralMatrix(v);
    printVector(newVec);
    return 0;
}
