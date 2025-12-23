#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &v)
{
    int r = v.size();
    int c = v[0].size();
    int sr = 0, sc = 0;
    int er = r - 1, ec = c - 1;
    vector<int> ans;
    while (sr <= er && sc <= ec)
    {
        // top
        for (int i = sc; i <= ec; i++)
        {
            ans.push_back(v[sr][i]);
        }
        // right
        for (int i = sr + 1; i <= er; i++)
        {
            ans.push_back(v[i][ec]);
        }
        // bottom
        for (int i = ec - 1; i >= sc; i--)
        {
            if (sr == er)
            {
                break;
            }
            ans.push_back(v[er][i]);
        }
        // left
        for (int i = er - 1; i >= sr + 1; i--)
        {
            if (sc == ec)
            {
                break;
            }
            ans.push_back(v[i][sc]);
        }
        sr++;
        ec--;
        er--;
        sc++;
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
