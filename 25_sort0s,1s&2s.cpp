#include <iostream>
#include <vector>
using namespace std;

// bruteForceAppraoch
void sortOptimize(vector<int> &v, int n)
{
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            count0++;
        if (v[i] == 1)
            count1++;
        if (v[i] == 2)
            count2++;
    }
    int idx = 0;
    for (int i = 0; i < count0; i++)
    {
        v[idx++] = 0;
    }
    
    for (int i = 0; i < count1; i++)
    {
        v[idx++] = 1;
    }
    
    for (int i = 0; i < count2; i++)
    {
        v[idx++] = 2;
    }
}
// Optimize Appraoach
// Optimal Appraoach

void sort(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[i])
            {
                swap(v[i], v[j]);
            }
        }
    }
}

void printArray(vector<int> &a, int n)
{
    for (int num : a)
    {
        cout << num << " ";
    }
}

int main()
{
    vector<int> v = {2, 0, 2, 1, 1, 0};
    int n = v.size();
    // sort(v, n);
    sortOptimize(v, n);
    printArray(v, n);
    return 0;
}