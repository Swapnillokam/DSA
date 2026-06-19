//recursions 
//59_MergeSort

//https://leetcode.com/problems/sort-an-array/description/
//912. Sort an Array(merge sort array)
/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
*/

//TC - O(nlogn)
//SC - O(n)
class Solution {
public:
    void merge(vector<int>& a, int st, int mid, int end) {
        vector<int> temp(end - st + 1);
        int left = st, right = mid + 1, index = 0;
        while (left <= mid && right <= end) {
            if (a[left] <= a[right]) {
                temp[index] = a[left];
                left++;
            } else {
                temp[index] = a[right];
                right++;
            }
            index++;
        }
        while (left <= mid) {
            temp[index] = a[left];
            left++;
            index++;
        }
        while (right <= end) {
            temp[index] = a[right];
            right++;
            index++;
        }
        index = 0;
        while (st <= end) {
            a[st] = temp[index];
            st++;
            index++;
        }
    }

    void mergeSort(vector<int>& a, int st, int end) {
        if (st == end)
            return;
        int mid = st + (end - st) / 2;
        mergeSort(a, st, mid);
        mergeSort(a, mid + 1, end);
        merge(a, st, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

//quicksort - gives TLE - because quick sort avg TC is O(nlogn) (SC is 0(logN))and not worst case TC(SC is 0(N2))(worst case - for sorted array in ascending or descending)
class Solution {
public:
    int partition(vector<int>& a,int st, int end) {
        int pos = st;
        for (int i = st; i <= end; i++) {
            if (a[i] <= a[end]) {
                swap(a[pos], a[i]);
                pos++;
            }
        }
        return pos - 1;
    }

    void quickSort(vector<int>& a, int st, int end) {
        if (st >= end)
            return;
        int pivot = partition(a,st,end);
        // left
        quickSort(a, st, pivot - 1);
        // right
        quickSort(a, pivot, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};