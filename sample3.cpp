#include <iostream>
#include <vector>
using namespace std;

void spiralMatrix(vector<vector<int>> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (i == j)
            {
                cout << v[i][j] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    spiralMatrix(v);
    return 0;
}