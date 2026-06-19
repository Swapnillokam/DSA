//65_PermutationWithRepeatitionAndWaysToSumN
//https://leetcode.com/problems/permutations-ii/description/

/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    void permute(vector<int>& nums, vector<vector<int>>& ans,
                                int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        vector<bool> use(21, 0);
        for (int i = index; i < nums.size(); i++) {
            if (use[nums[i] + 10] == 0) {
                swap(nums[index], nums[i]);
                permute(nums, ans, index + 1);
                swap(nums[index], nums[i]);
                use[nums[i] + 10] = 1;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, ans, 0);
        return ans;
    }
};


//https://www.geeksforgeeks.org/problems/ways-to-sum-to-n5759/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks

/*
Given an array arr[] of m distinct positive integers and an integer n, count the total number of ways to form n by adding the array elements. Repetition of elements is allowed and different arrangements are counted as separate ways.

Note: Since the answer can be very large, return it modulo 10^9 + 7.

Examples:

Input: arr[] = {1,5,6}, n = 7
Output: 6
Explanation: The different ways are: 1+1+1+1+1+1+1, 1+1+5, 1+5+1, 5+1+1, 1+6, 6+1
Input: arr[] = {1,2,3}, n = 3
Output: 4
Explanation: The different ways are: 1+1+1, 1+2, 2+1, 3
*/
//gives TLE
//will be solve during DP
class Solution {
  public:
    int countWays(vector<int>& arr, int m) {
        // code here.
        if(m == 0)
        {
            return 1;
        }
        if(m < 0)
        {
            return 0;
        }
        int ans = 0;
        for(int i =0;i<arr.size();i++)
        {
            ans += countWays(arr,m-arr[i]);
        }
        return ans;
        
    }
};
