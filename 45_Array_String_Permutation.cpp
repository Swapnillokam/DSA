#include <iostream>
#include <vector>

using namespace std;

void getPermutations(vector<int> &v, int n, vector<vector<int>> &ans, int idx)
{
    if (idx == n)
    {
        ans.push_back(v);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        swap(v[i], v[idx]);
        getPermutations(v, n, ans, idx + 1);
        swap(v[i], v[idx]);
    }
}

int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> ans;
    getPermutations(v, v.size(), ans, 0);
    for (vector<int> x : ans)
    {
        for (int y : x)
        {
            cout << y;
        }
        cout << ", ";
    }
    return 0;
}