//99_QueueHard


//https://leetcode.com/problems/sliding-window-maximum/description/
//239. Sliding Window Maximum
/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

//GIVES TLE(0(n2))
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        {
            int total = INT_MIN;
            for (int i = 0; i <= nums.size() - k; i++) {
                for (int j = i; j < i + k; j++) {
                    total = max(total, nums[j]);
                }
                ans.push_back(total);
            }
        }
        return ans;
    }
};

//optimized approach-0(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> d;
        // initialization
        for (int i = 0; i < k - 1; i++) {
            if (d.empty())
                d.push_back(i);
            else {
                while (!d.empty() && nums[i] > nums[d.back()]) {
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
        // last elements in the window
        for (int i = k - 1; i < nums.size(); i++) {
            while (!d.empty() && nums[i] > nums[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
            if (d.front() <= i - k)
                d.pop_front();
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};


//995. Minimum Number of K Consecutive Bit Flips
//https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
/*
You are given a binary array nums and an integer k.

A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].
Example 2:

Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
Example 3:

Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation: 
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
*/

//Gives TLE - ownmethod - 0(n2)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int count = 0;
        int bits = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (i + k > nums.size())
                    return -1;
                for (int j = i; j < i + k; j++) {
                    if (nums[j] == 0) {
                        nums[j] = 1;
                        count--;
                    } else {
                        nums[j] = 0;
                        count++;
                    }
                }
                bits++;
            }
        }
        if (count <= 0)
            return bits;
        return -1;
    }
};

//not able to understand the optimized solution - check the video later