//61_Subset_Parenthesis
//https://leetcode.com/problems/subsets/description/
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

//TC - 0(2^n) and SC - 0(n*2^n)
class Solution {
public:
    void subSequence(vector<int>& a, int index, int end, vector<int> temp,
                     vector<vector<int>>& ans) {
        if (index > end) {
            ans.push_back(temp);
            return;
        }
        subSequence(a, index + 1, end, temp, ans);
        temp.push_back(a[index]);
        subSequence(a, index + 1, end, temp, ans);
    }
//TC - 0(2^n) and SC - 0(n)->confirm again
void subSequence(vector<int>& a, int index, int end, vector<int> &temp,
                     vector<vector<int>>& ans) {
        if (index > end) {
            ans.push_back(temp);
            return;
        }
        subSequence(a, index + 1, end, temp, ans);
        temp.push_back(a[index]);
        subSequence(a, index + 1, end, temp, ans);
	temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        subSequence(nums, 0, nums.size() - 1, temp, ans);
        return ans;
    }
};



//subset sum 
void subsetSum(vector<int> &a,int index, int size,int sum)
    {
        if(index==size)
        {
            cout<<sum<<" ";
            return;
        }
        
        subsetSum(a,index+1,size,sum);
        subsetSum(a,index+1,size,sum+a[index]);
        
    }




//TC - O(2^n) SC- ?	
//https://leetcode.com/problems/generate-parentheses/description/
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
class Solution {
public:
    void validParenthesis(int n, int left, int right, string& temp,
                          vector<string>& s) {
        if (left == n && right == n) {
            s.push_back(temp);
            return;
        }

        if (left < n) {
            temp.push_back('(');
            validParenthesis(n, left + 1, right, temp, s);
            temp.pop_back();
        }
        if (right < left) {
            temp.push_back(')');
            validParenthesis(n, left, right + 1, temp, s);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> s;
        string temp;
        validParenthesis(n, 0, 0, temp, s);
        return s;
    }
};

//lecture no - 62 , 2nd problem
//TC - 0(2^n)

// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>

using namespace std;

bool sumTarget(vector<int> &v,int index,int n, int target)
{
    if(target == 0)
        return true;
    if(target < 0 || index == n)
        return false;
    return sumTarget(v,index+1,n,target) || sumTarget(v,index+1,n,target - v[index]);
}

int main() {
    
    vector<int> v = {2,4,1,8,7};
    int target = 25;
    cout<<sumTarget(v,0,v.size(),target);
    return 0;
}