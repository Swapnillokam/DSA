#include <iostream>
#include <vector>
using namespace std;

// leetcode Q.238
// bruteforce - 0(n2)
vector<int> arrayProduct(vector<int> &vec)
{
    int n = vec.size();
    vector<int> p;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                product *= vec[j];
            }
        }
        p.push_back(product);
    }
    return p;
}


//not ablt to understand check the video again
// optimize way - 0(n)
vector<int> arrayProduct1(vector<int> &vec)
{
    int n = vec.size();
    vector<int> p;
    vector<int> prefix;
    vector<int> suffix;
    prefix[0] = 1;
    suffix[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * vec[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * vec[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        p[i] = prefix[i] * suffix[i];
    }
    return p;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    // vector<int> p = arrayProduct(vec);
    vector<int> p = arrayProduct1(vec);
    for (int value : p)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}