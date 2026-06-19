//98_QueueSlidingWindow
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void display(queue<int> q)
{
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void slidingWindow(vector<int> &v,int k){
    queue<int> q;
    for(int i=0;i<k-1;i++){
        q.push(v[i]);
    }
    int i=q.size();
    while(i<v.size())
    {
        q.push(v[i]);
        display(q);
        q.pop();
        i++;
    }
}



int main() {
    // Write C++ code here
    vector<int> v = {3,6,2,7,8,11};
    int k = 3;
    slidingWindow(v,k);

    return 0;
}

//first-negative-integer-in-every-window-of-size-k3345
//https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
/*
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.
*/
//gives TLE
class Solution {
public:
    int display(queue<int> q) {
        while (!q.empty()) {
            if (q.front() < 0)
                return q.front();
            q.pop();
        }
        return 0;
    }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        vector<int> v;
        for (int i = 0; i < k - 1; i++) {
            q.push(arr[i]);
        }
        int i = q.size();
        while (i < arr.size()) {
            q.push(arr[i]);
            v.push_back(display(q)); 
            q.pop();
            i++;
        }
        return v;
    }
};


//first-non-repeating-character-in-a-stream-of-characters
//https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

string Solution::solve(string A) {
        string B = "";
        queue<char> c;
        vector<int> repeated(26, 0);
        for (int i = 0; i < A.size(); i++) {
            // repeated
            if (repeated[A[i] - 'a'] = > 1) {
                repeated[A[i] - 'a']++;
                while (!q.empty() && repeated[q.front() - 'a'] > 1) {
                    q.pop();
                }
                if (q.empty())
                    B += "#";
                else
                    B += q.front();
            }
            // non repeated
            else {
                repeated[A[i] - 'a']++;
                q.push(A[i]);
                while (repeated[q.front() - 'a'] > 1) {
                    q.pop();
                }

                B += q.front();
            }
        }
    }
