//94_1_StackGetMinFromStack
//https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class SpecialStack {
  public:
    stack<int> s1;
    stack<int> s2;
    SpecialStack() {
    }

    void push(int x) {
        s1.push(x);
        if(s2.empty())
            s2.push(x);
        else
            s2.push(min(x,s2.top()));
    }

    void pop() {
        if(s1.empty()) return;
        s1.pop();
        s2.pop();
    }

    int peek() {
        if(s1.empty())
            return -1;
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }

    int getMin() {
        if(s2.empty()) return -1;
        return s2.top();
    }
};

//without using extra stack - check video (problem statement is slightly different in the video)

//94_2_StackMaxMinEveryWindowSize
//https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?page=1&difficulty%5B%5D=2&category%5B%5D=Stack&sortBy=submissions

/*
Max of min for every window size
Difficulty: HardAccuracy: 42.9%Submissions: 83K+Points: 8Average Time: 45m
You are given an integer array arr[], the task is to find the maximum of minimum values for every window size k where 1≤ k ≤ arr.size().

For each window size k, consider all contiguous subarrays of length k, determine the minimum element in each subarray, and then take the maximum among all these minimums.

Return the results as an array, where the element at index i represents the answer for window size i+1.

Examples :

Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10] 
Explanation: 
Window size 1: minimums are [10, 20, 30, 50, 10, 70, 30], maximum of minimums is 70.
Window size 2: minimums are [10, 20, 30, 10, 10, 30], maximum of minimums is 30.
Window size 3: minimums are [10, 20, 10, 10, 10], maximum of minimums is 20.
Window size 4–7: minimums are [10, 10, 10, 10], maximum of minimums is 10.
*/

// this solution gives TLE - i.e 0(n3)
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++)
        {
           for(int j=0;j<n-i;j++)
           {
               int mini = INT_MAX;
               for(int k = j;k<j+i+1;k++)
               {
                   mini = min(mini,arr[k]);
               }
               ans[i] = max(ans[i],mini);
           }
        }
        return ans;
    }
};

//tired leaving the video - check later to do the above task in 0(n)