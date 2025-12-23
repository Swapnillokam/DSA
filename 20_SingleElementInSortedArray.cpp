#include <iostream>
#include <vector>
using namespace std;

// leetcode - Q.540
// bruteforce
// each element appears exactly twice except the uniqe element -- conclusion -> array size is odd
int uniqueElemnet(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (i != j)
            {
                if (v[i] == v[j])
                {
                    count++;
                }
            }
        }
        if (count > 0)
            continue;
        else
            return v[i];
    }
}

// using binary approach- check the video for logic -- 0(logn)
//some error -check the code again
int uniqueElemnet1(vector<int> &v)
{
    int st = 0;
    int end = v.size() - 1;

    // corner case
    if (end == 0)
        return v[0];

    while (st < end)
    {
        int mid = st + (end - st) / 2;

        // corner case
        if (mid == 0 && v[0] != v[1])
            return v[mid];
        if (mid == end && v[end] != v[end - 1])
            return v[mid];

        if (v[mid] != v[mid + 1] && v[mid] != v[mid - 1])
        {
            return v[mid];
        }
        if (mid % 2 != 0)
        {
            if (v[mid] == v[mid + 1])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else if (mid % 2 == 0)
        {
            if (v[mid] == v[mid + 1])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    vector<int> v2 = {3, 3, 7, 7, 10, 11, 11};
    // cout << "The unique element in the array is " << uniqueElemnet(v2) << endl;
    cout << "The unique element in the array is " << uniqueElemnet1(v2) << endl;
    return 0;
}