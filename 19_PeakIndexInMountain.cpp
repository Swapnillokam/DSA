#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// leetcode Q.852
// Note - array is guaranted to be a mountain array

// bruteforce
int peakElement(vector<int> &v)
{
   int maxValue = INT_MIN;
   for (int i = 0; i <= v.size() - 1; i++)
   {
      maxValue = max(v[i], maxValue);
   }
   return maxValue;
}

// optimization -> 0(logn)
int peakElement1(vector<int> &v)
{
   int st = 0;
   int end = v.size() - 1;
   while (st <= end)
   {
      int mid = st + (end - st) / 2;
      if (v[mid - 1] < v[mid] && v[mid] > v[mid + 1])
      {
         cout << "The peak element is " << v[mid] << endl;
         return mid;
      }
      else if (v[mid] > v[mid + 1])
      {
         end = mid - 1;
      }
      else if (v[mid] > v[mid - 1])
      {
         st = mid + 1;
      }
   }
   return -1;
}

int main()
{
   vector<int> vec = {0, 3, 8, 9, 5, 2};
   cout << "The peak element for given array is at " << peakElement(vec) << endl;
   cout << "and its position is " << peakElement1(vec) << endl;
   return 0;
}