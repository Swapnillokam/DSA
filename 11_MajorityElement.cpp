#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int> &a)
{
    int length = a.size();
    for (int i = 0; i < length; i++)
    {
        int frequency;
        for (int j = i + 1; j < length; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

vector<int> pairSum(vector<int> a, int target)
{
    int length = a.size();
    vector<int> ans;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (a[i] + a[j] == target)
            {
                ans.push_back(a[i]);
                ans.push_back(a[j]);
                return ans;
            }
        }
    }
    return ans;
}

// optimized - converting to linear complexity i.e. 0(n)
// when we already know that the elements are sorted in ascending order
vector<int> pairSum1(vector<int> a, int target)
{
    int length = a.size();
    int end = length - 1;
    vector<int> ans;
    for (int start = 0; start < length; start++)
    {
        while (start < end)
        {
            int pairSum = a[start] + a[end];

            if (pairSum < target)
            {
                start++;
            }
            else if (pairSum > target)
            {
                end--;
            }
            else if (pairSum == target)
            {
                ans.push_back(a[start]);
                ans.push_back(a[end]);
                return ans;
            }
        }
    }
    return ans;
}

// leetcode 169- majority element
// Given that majority element always exits inthe array

// 1. Brute force appraoch  -- 0(n2)
int majorityElement(vector<int> vec)
{
    int length = vec.size();
    int majorElement = length / 2;

    for (int value : vec)
    {
        int counter = 0;
        for (int element : vec)
        {
            if (element == value)
            {
                counter++;
            }
        }
        if (counter > majorElement)
        {
            return value;
        }
    }
    return 0;
}

// 2. optimized method ( n + nlog(n) = 0(nlog(n)) )
int majorityElement2(vector<int> &a)
{
    int length = a.size();
    sortArray(a);
    // sort(a.begin(),a.end());
    int frequency = 1;
    int ans = a[0];
    for (int i = 1; i < length; i++)
    {
        if (a[i] == a[i - 1])
        {
            frequency++;
        }
        else
        {
            frequency = 1;
            ans = a[i];
        }
        if (frequency > length / 2)
        {
            return ans;
        }
    }
    return 0;
}

// 3. Moore's vooting algo(0(n))
int majorityElement3(vector<int> &a)
{
    int length = a.size();
    int frequency = 0;
    int ans = 0;
    for (int i = 0; i < length; i++)
    {
        if (frequency == 0)
        {
            ans = a[i];
        }
        if (a[i] == ans)
        {
            frequency++;
        }
        else
        {
            frequency--;
        }
    }

    // if all the values are differnet in the array
    int count = 0;
    for (int value : a)
    {
        count++;
    }
    if (count > length / 2)
    {
        return ans;
    }
    else
    {
        return -1;
    }
    return ans;
}

int main()
{
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 26;
    // vector<int> vec = pairSum(nums, target);
    // for (int value : vec)
    // {
    //     cout << value << " ";
    // }

    // vector<int> vec = pairSum1(nums, target);
    // for (int value : vec)
    // {
    //     cout << value << " ";
    // }

    vector<int> nums = {1, 2, 2, 0, 1, 1};
    // cout << "Majority element is " << majorityElement(nums) << endl;

    // vector<int> nums1 = {2, 34, 2, 65, 32, 67};
    // sortArray(nums1);
    // for (int value : nums1)
    // {
    //     cout << value << " ";
    // }

    // cout << "Majority element is " << majorityElement2(nums) << endl;
    cout << "Majority element is " << majorityElement3(nums) << endl;
    return 0;
}