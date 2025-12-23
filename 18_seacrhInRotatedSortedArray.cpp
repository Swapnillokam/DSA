#include <iostream>
#include <vector>
using namespace std;

// leetcode Q.33
// modified binary search in a rotated sorted
int search(vector<int> &vec, int target)
{
    int st = 0;
    int end = vec.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target == vec[mid])
        {
            return mid;
        }
        if (vec[st] <= vec[mid]) // checks if left side is sorted
        {
            if (vec[st] <= target && target <= vec[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else // right sorted
        {
            if (vec[mid] <= target && target <= vec[end])
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
    vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "The target value for given array is at " << search(vec, target) << endl;
    return 0;
}