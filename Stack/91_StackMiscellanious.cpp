//91_StackMiscellanious
//https://www.geeksforgeeks.org/problems/next-greater-element/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
/*
Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.

The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.

Note: Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

Examples: 
  
|Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.
Input: arr[] = [0, 2, 3, 1, 1]
Output: [2, 3, -1, 2, 2]
Explanation:
The next greater element for 0 is 2.
The next greater element for 2 is 3.
The next greater element for 3 does not exist, so return -1.
The next greater element for 1 is 2 (from circular traversal).
The next greater element for 1 is 2 (from circular traversal).
*/
//the below is for linear array 
vector<int> nextGreater(vector<int> &arr) {
        // code here
        vector<int> ans(arr.size(),-1);
        stack<int> s;
        for(int i = 0;i<arr.size();i++)
        {
            while(!s.empty() && arr[s.top()]<arr[i])
            {
                ans[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }

//for circular array 
//not understood -- understood - just iterating the twice array since its circular so that two times traversal happens
vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> s;   // stores indices

        // traverse array twice to simulate circular behavior
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n; // iterating array second time

            while (!s.empty() && arr[s.top()] < arr[idx]) {
                ans[s.top()] = arr[idx];
                s.pop();
            }

            // push index only during first pass
            if (i < n)
                s.push(idx);
        }
        return ans;
    }


//https://www.naukri.com/code360/problems/next-smaller-element_1112581?leftPanelTabValue=SUBMISSION
// Next Smaller Element
/*
Problem statement
You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.

Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.

If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:

If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 5
0 <= ARR [i] <= 10 ^ 9

Time Limit: 1sec.
Sample Input 1:
2
4
2 1 4 3
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1
Explanation for Sample Input 1:
For the first test case : 
1) For ARR [1] = 2 ,  the next smaller element is 1. 
2) For ARR [2] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
3) For ARR [3] = 4 ,  the next smaller element is 3.
4) For ARR [4] = 3 ,  the next smaller element is -1 as no element exists in the right of it.
Hence, we will return the array [ 1, -1, 3, -1] in this case.

For the second test case :
1) For ARR [1] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
2) For ARR [2] = 3 ,  the next smaller element is 2.
3) For ARR [3] = 2 ,  the next smaller element is -1 as no element exists in the right of it.
Hence we will return the array [ -1, 2, -1 ] in this case.
Sample Input 2:
2
4
1 2 3 4
2
5 0
Sample Output 2:
-1 -1 -1 -1
 0 -1
*/
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i = 0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}


//https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
//Smaller on Left
/*
Input: arr[] = [1, 5, 0, 3, 4, 5]
Output:       [-1, 1, -1, 0, 3, 4]
Explaination: 
There is no number to the left of 1,  so we return -1. 
After that, the number is 5,  and the nearest smaller number on its left is 1. 
 Next, the number is 0, and there is no smaller number on the left, so we return -1.
Then comes 3, and the nearest smaller number on its left is 0.
After that, the number is 4, and the nearest smaller number on the left is 3. 
Finally, the number is 5, and the nearest smaller number on its left is 4.
*/
vector<int> leftSmaller(vector<int> arr) {
        // code here
        vector<int> ans(arr.size(),-1);
        stack<int> s;
        for(int i =arr.size()-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>arr[i]){
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }



//https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
//Stock span problem
/*
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
You are given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 10 is greater than equal to 10 and there are no more days behind it so the span is 1, 4 is greater than equal to 4 and smaller than 10 so the span is 1, 5 is greater than equal to 4 and 5 and smaller than 10 so the span is 2, and so on. Hence the output will be [1, 1, 2, 4, 5, 1].
*/
vector<int> calculateSpan(vector<int>& arr) {
       vector<int> ans(arr.size(),1);
       stack<int> s;
       for(int i=arr.size()-1;i>=0;i--)
       {
           while(!s.empty() && arr[s.top()]<arr[i])
           {
               ans[s.top()]=s.top()-i;
               s.pop();
           }
           s.push(i);
       }
       while(!s.empty())
       {
           ans[s.top()] = s.top()+1;
           s.pop();
       }
       return ans;
        
    }


