//63_PerfectSumTargetSum
//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks

/*
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
*/

//gives TLE - sol while learning dynamic programming
//TC - O(2^n) SC - 
int perfectSum(vector<int> &v,int index,int n, int sum)
{
    
    if(index == n)
    {
        if(sum == 0)
            return 1;
        return 0;
    }
    return perfectSum(v, index + 1, n, sum) + perfectSum(v, index + 1, n, sum - v[index]);
    
}

int subSum(vector<int> &v,int index,int n, int sum)
{
    if(sum == 0)
        return 1;
    if(index == n || sum < 0)
        return 0;
    return subSum(v, index + 1, n, sum) + subSum(v, index, n, sum - v[index]);
    
}

int main() {
    vector<int> v1 = {2,5,6,1};
    int sum = 8;
    cout << perfectSum(v1, 0, v1.size(), sum) << endl;
	
    vector<int> v2 = {2,3,4};
    int sum2 = 6;
    cout << subSum(v2, 0, v2.size(), sum2) << endl;

    //check difference between both the functions 
    return 0;
}