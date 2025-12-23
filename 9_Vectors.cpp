#include <iostream>
#include <vector>
using namespace std;

// leetcode 136.single number
// Q. given a non empty array of integers nums, every element appears twice except one , find that single one
//  note - you must implement a solution with a linear runtime complexity and use only constant extra space
//  ex =>
//  imput nums = {1,2,1,2,4}
//  output = 4
int uniqueValue(vector<int> &nums)
{
    int ans = 0;
    for (int value : nums)
    {
        //check rules for bitwise opertor of XOR
        ans = ans ^ value   ;
    }
    return ans;
}
void subArray()
{
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    for (int st = 0; st < n; st++)
    {
        for (int end = st; end < n; end++)
        {
            // for (int i = end; i < end; i++)
            // {
            //     cout << a[i];
                cout << a[end];
            // }
            // cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    // vector<int> vec = {1, 2, 3};
    // cout << vec[0] << endl;
    // vector<int> vec1(3, 0);
    // // cout << vec1[0] << endl;
    // // cout << vec1[1] << endl;
    // // cout << vec1[2] << endl;

    // for (int i : vec1)
    // {
    //     cout << i << endl;
    // }

    // vector<int> vec2 = {'a','b','c','d','e'};
    // for (char i : vec2)
    // {
    //     cout << i << endl;
    // }

    vector<int> vec = {1, 2, 1, 3, 2};
    cout << "unique value is " << uniqueValue(vec) << endl;
    subArray();
    return 0;
}