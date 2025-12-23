#include <iostream>
#include <vector>
using namespace std;

// binary search - 0(log(n))
// array shuold be sorted
int binarySearch(vector<int> &vec, int target)
{
    int n = vec.size();
    int st = 0;
    int end = n - 1;        

    while (st <= end)
    {
        // int mid = (st + end) / 2;
        int mid = st + (end - st) / 2; // to avoid the overflow -> check the video
        if (target > vec[mid])
        {
            st = mid + 1;
        }
        else if (target < vec[mid])
        {
            end = mid - 1;
        }
        else
        {
            cout << vec[mid] << endl;
            return mid;
        }
    }
    return -1;
}

int recursiveBinarySearch(vector<int> &vec, int target, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target > vec[mid])
            return recursiveBinarySearch(vec, target, mid + 1, end);
        else if (target < vec[mid])
            return recursiveBinarySearch(vec, target, st, mid - 1);
        else
            return mid;
    }
    cout << "Target is not found" << endl;
    return -1;
}

int main()
{
    vector<int> vec1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    vector<int> vec2 = {-1, 0, 3, 5, 9, 12};    // even
    int target1 = 12;
    int target2 = 0;
    cout << "The target value for odd array is at " << binarySearch(vec1, target1) << endl;
    cout << "The target value for even array is at " << binarySearch(vec1, target2) << endl;

    cout << "using recursive method" << endl;
    cout << "The target value for even array is at " << recursiveBinarySearch(vec1, target1, 0, vec1.size() - 1) << endl;
    return 0;
}