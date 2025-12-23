#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// brute force appraoch
// 0(n3)
int numberOfSubarrays(vector<int> &v, int target)
{
    int sum;
    int count = 0;
    for (int st = 0; st < v.size(); st++)
    {
        for (int as = st; as < v.size(); as++)
        {
            sum = 0;
            // cout << " Sum=" << sum << "-";
            for (int se = st; se <= as; se++)
            {
                cout << v[se];

                sum += v[se];
            }
            if (sum == target)
            {
                count++;
            }
            // cout << "=" << sum << "    ";
            cout << " ";
        }
        cout << endl
             << endl;
    }
    return count;
}

// better
// 0(n2)
int numberOfSubarraysOptimal(vector<int> &v, int target)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum == target)
            {
                count++;
                continue;
            }
        }
    }
    return count;
}

// optimized (prefix sum)
// 0(n)
int numberOfSubarraysOptimized(vector<int> &v, int target)
{
    int count = 0;
    int n = v.size();
    vector<int> prefixSum(n, 0);

    prefixSum[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }

    unordered_map<int, int> m; // PS,freq
    for (int j = 0; j < n; j++)
    {
        if (prefixSum[j] == target)
        {
            count++;
        }

        int value = prefixSum[j] - target;
        if (m.find(value) != m.end())
        {
            count += m[value];
        }

        if (m.find(prefixSum[j]) == m.end())
        {
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]]++;
    }

    return count;
}

int main()
{
    vector<int> v = {9, 4, 20, 3, 10, 5};
    int target = 33;
    // cout << numberOfSubarrays(v, target);
    // cout << numberOfSubarraysOptimal(v, target);
    cout << numberOfSubarraysOptimized(v, target);
    return 0;
}
