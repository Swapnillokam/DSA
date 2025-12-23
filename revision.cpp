// #include <iostream>
// #include <string>
// #include <math.h>
// #include <climits>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void squarePattern()
// {
//     for (int i = 1; i < 5; i++)
//     {
//         for (int j = 1; j < 5; j++)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }

// void squareStarPattern()
// {
//     for (int i = 1; i < 5; i++)
//     {
//         for (int j = 1; j < 5; j++)
//         {
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
// }

// void charSquarePattern()
// {
//     cout << "Method 1" << endl;
//     for (int i = 1; i < 5; i++)
//     {
//         char ch = 'A';
//         for (int j = 1; j < 5; j++)
//         {
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }

//     cout << "Method 2" << endl;
//     for (char i = 'A'; i < 'E'; i++)
//     {
//         for (char j = 'A'; j < 'E'; j++)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }

// void squareStarPattern2()
// {
//     int x = 1;

//     for (int i = 1; i < 5; i++)
//     {
//         for (int j = 1; j < 5; j++)
//         {
//             cout << x << " ";
//             x++;
//         }
//         cout << endl;
//     }
// }

// void charSquarePattern2()
// {
//     char ch = 'A';

//     for (int i = 1; i < 5; i++)
//     {
//         for (int j = 1; j < 5; j++)
//         {
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }
// }

// void starTrianglePattern2()
// {
//     char ch = 'A';

//     for (int i = 1; i < 5; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
// }

// void TrianglePattern2()
// {
//     for (int i = 1; i < 5; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }

// void mixPractice()
// {
//     int n = 5;
//     // char a = 'A';

//     // // A
//     // // B A
//     // // C B A
//     // // D C B A
//     // for (char i = 'A'; i < 'E'; i++)
//     // {
//     //     for (char j = i; j >= 'A'; j--)
//     //     {
//     //         cout << j << " ";
//     //     }
//     //     cout << endl;
//     // }

//     // cout << int(a);
//     // cout << char(65);
//     // cout << endl;
//     // // A
//     // // B A
//     // // C B A
//     // // D C B A
//     // for (int i = int(a); i < int('E'); i++)
//     // {
//     //     for (int j = i; j >= int('A'); j--)
//     //     {
//     //         cout << char(j) << " ";
//     //     }
//     //     cout << endl;
//     // }

//     // //  AAAA
//     // //   BBB
//     // //    CC
//     // //     D
//     // char ch = 'A';
//     // for (int i = 1; i < 5; i++)
//     // {
//     //     for (int j = i; j > 0; j--)
//     //     {
//     //         cout << " ";
//     //     }
//     //     for (int k = i; k <= 4; k++)
//     //     {
//     //         cout << ch;
//     //     }
//     //     cout << endl;
//     //     ch++;
//     // }

//     // for (int i = 1; i < n; i++)
//     // {
//     //     int a = 1;
//     //     for (int j = i; j < n - 1; j++)
//     //     {
//     //         cout << " ";
//     //     }
//     //     for (int k = 1; k <= i; k++)
//     //     {
//     //         cout << k;
//     //     }
//     //     for (int l = i-1; l > 0; l--)
//     //     {
//     //         cout << l;
//     //     }

//     //     cout << endl;
//     // }

//     // //    *
//     // //   * *
//     // //  *   *
//     // // *     *
//     // //  *   *
//     // //   * *
//     // //    *
//     //     // top
//     //     for (int i = 1; i < n; i++)
//     //     { // left
//     //         for (int j = 1; j < n - i; j++)
//     //         {
//     //             cout << " ";
//     //         }
//     //         cout << "*";

//     //         if (i > 1)
//     //         {
//     //             for (int j = 1; j <= 2 * i - 3; j++)
//     //             {
//     //                 cout << " ";
//     //             }
//     //             cout << "*";
//     //         }

//     //         cout << endl;
//     //     }

//     //     // bottom
//     //     for (int i = 1; i < n - 1; i++)
//     //     {
//     //         for (int j = 1; j <= i; j++)
//     //         {
//     //             cout << " ";
//     //         }
//     //         cout << "*";
//     //         if ((2 * ((n - 1) - i)) - 3 > 0)
//     //         {
//     //             for (int k = 1; k <= (2 * ((n - 1) - i)) - 3; k++)
//     //             {
//     //                 cout << " ";
//     //             }
//     //             cout << "*";
//     //         }
//     //         cout << endl;
//     //     }

//     int a = 4;
//     // top
//     for (int i = 1; i <= a; i++)
//     {
//         for (int st = 1; st <= i; st++)
//         {
//             cout << "*";
//         }
//         for (int sp = 1; sp <= 2 * (a + 1 - i) - 2; sp++)
//         {
//             cout << " ";
//         }
//         for (int st = 1; st <= i; st++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     // bottom
//     for (int i = 1; i <= a; i++)
//     {
//         for (int st = a; st >= i; st--)
//         {
//             cout << "*";
//         }
//         for (int sp = 1; sp <= 2 * (i - 1); sp++)
//         {
//             cout << " ";
//         }
//         for (int st = a; st >= i; st--)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

// bool checkPrimeNumm(int n)
// {
//     for (int i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << "Is not a prime number" << endl;
//             return false;
//         }
//     }
//     return true;
// }

// void finnaciSeries(int n)
// {
//     int a = 0;
//     int b = 1;
//     for (int i = 0; i < n; i++)
//     {
//         cout << a << " ";
//         int next = a + b;
//         a = b;
//         b = next;
//     }
// }

// void decToBin(int n)
// {
//     int rem, ans = 0, power = 1;
//     while (n > 0)
//     {

//         rem = n % 2;
//         n /= 2;
//         ans += power * rem;
//         power *= 10;
//     }
//     cout << "Binary conversion is " << ans << endl;
// }

// void BinaryToDec(int n)
// {
//     int rem, ans = 0, power = 1;
//     cout << "Decimal conversion of " << n;
//     while (n > 0)
//     {

//         rem = n % 10;
//         n /= 10;
//         ans = ans + (power)*rem;
//         power *= 2;
//     }
//     cout << " is " << ans << endl;
// }

// void reverseInteger(int n)
// {
//     int rem, ans = 0, number = n;
//     while (n > 0)
//     {
//         rem = n % 10;
//         ans = ans * 10 + rem;
//         n /= 10;
//     }
//     cout << "reversed integer of " << number << " is " << ans << endl;
// }

// void smallestArrayElement(int arr[], int length)
// {

//     int smallest = INT_MAX;
//     int largest = INT_MIN;

//     for (int i = 0; i <= length - 1; i++)
//     {
//         if (smallest > arr[i])
//         {
//             smallest = arr[i];
//         }
//         if (largest < arr[i])
//         {
//             largest = arr[i];
//         }
//     }
//     cout << "samllest number is " << smallest << endl;
//     cout << "largest number is " << largest << endl;
// }

// void subArray(vector<int> &v)
// {
//     for (int st = 0; st < v.size(); st++)
//     {
//         for (int end = st; end < v.size(); end++)
//         {
//             cout << v[end];
//         }
//         cout << endl;
//     }
// }

// void noofSubarraysAndMaxSum()
// {
//     vector<int> v = {3, -4, 5, 4, -1, 7, -8};
//     // vector<int> v = {1, 2, 3, 4, 5};
//     int maxSum = INT_MIN;
//     // brute force 0(n^3)
//     //  for (int st = 0; st < v.size(); st++)
//     //  {
//     //      for (int end = st; end < v.size(); end++)
//     //      {
//     //          int sum = 0;
//     //          for (int i = st; i <= end; i++)
//     //          {
//     //              cout << v[i];
//     //              sum = sum + v[i];
//     //              maxSum = max(maxSum, sum);
//     //          }
//     //          cout << " ";
//     //      }
//     //      cout << endl;
//     //  }

//     // better 0(n^2)
//     //  for (int st = 0; st < v.size(); st++)
//     //  {
//     //      int sum = 0;
//     //      for (int end = st; end < v.size(); end++)
//     //      {
//     //          cout << v[end];
//     //          sum = sum + v[end];
//     //          maxSum = max(maxSum, sum);
//     //          cout << " ";
//     //      }
//     //      cout << endl;
//     //  }

//     // kadanes algo 0(n)
//     int currentSum = 0;
//     for (int i = 0; i < v.size(); i++)
//     {
//         currentSum += v[i];
//         maxSum = max(currentSum, maxSum);
//         if (currentSum < 0)
//         {
//             currentSum = 0;
//         }
//     }

//     cout << "Max sum of subarray " << maxSum << endl;
// }

// vector<int> pairSum(vector<int> &v, int target)
// {
//     vector<int> ans;
//     int end = v.size() - 1;
//     for (int i = 0; i < v.size(); i++)
//     {
//         int st = i;

//         while (st < end)
//         {
//             if (v[end] > target)
//             {
//                 cout << "before while->end =" << v[end] << endl;
//                 cout << "end index =" << end << endl;
//                 end--;
//                 continue;
//             }
//             cout << "inside while->end =" << v[end] << endl;
//             if (v[st] + v[end] == target)
//             {
//                 ans.push_back(v[st]);
//                 ans.push_back(v[end]);
//             }
//             if (v[st] + v[end] > target)
//             {
//                 end--;
//             }
//             else
//             {
//                 st++;
//             }
//         }
//     }
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return ans;
// }

// void majorityElement(vector<int> &v)
// {
//     // bruteforce 0(n2)
//     // int maxCount = INT_MIN;
//     // for (int i = 0; i < v.size(); i++)
//     // {
//     //     int count = 1;
//     //     // cout << "for v[" << i << "]=" << v[i] << "=> ";
//     //     for (int j = i + 1; j < v.size(); j++)
//     //     {
//     //         if (v[i] == v[j])
//     //         {
//     //             // cout << "v[" << j << "]=" << v[j] << " ";
//     //             count++;
//     //         }
//     //     }

//     //     // cout << "count=" << count << " ";
//     //     maxCount = max(count, maxCount);
//     //     // cout << "maxCount=" << maxCount << endl;
//     //     // cout << endl;
//     //     if (count > v.size() / 2)
//     //     {
//     //         cout << "Majority Element is " << v[i] << endl;
//     //     }
//     // }
//     // cout << " and its count is " << maxCount << endl;

//     // better //0(nlogn)
//     // sortVector(v);
//     // or
//     // sort(v.begin(),v.end());
//     // int count = 1;
//     // int ans = v[0];
//     // for (int i = 0; i < v.size(); i++)
//     // {
//     //     cout << "ans=" << ans << endl;
//     //     cout << "v[" << i << "]=" << v[i] << endl;
//     //     cout << "v[" << i + 1 << "]=" << v[i + 1] << endl;
//     //     if (v[i] == v[i + 1])
//     //     {
//     //         count++;
//     //     }
//     //     else
//     //     {
//     //         count = 1;
//     //         ans = v[i+1];
//     //     }
//     //     cout << "count=" << count;
//     //     cout << endl;
//     //     if (count > v.size() / 2)
//     //         break;
//     // }
//     // cout << "majority element is " << ans << " and its count is " << count << endl;

//     int count = 0;
//     int ans = 0;
//     for (int i = 0; i < v.size(); i++)
//     {

//         if (count == 0)
//         {
//             ans = v[i];
//         }
//         if (v[i] == ans)
//         {
//             count++;
//         }
//         else
//         {
//             count--;
//         }
//         cout << "v[" << i << "]=" << v[i] << endl;
//         cout << "count=" << count << endl;
//         cout << "ans=" << ans << endl;
//         cout << endl;
//     }
//     cout << "ans " << ans << endl;
// }

// void power(double x, int n)
// {
//     // brute force
//     //  cout << x << "^" << n << endl;
//     //  long long power = n;
//     //  double y = x;
//     //  if (power < 0)
//     //  {
//     //      y = 1 / y;
//     //      n = -n;
//     //  }
//     //  double z = y;
//     //  double count = z;
//     //  cout << " y=" << y << endl;

//     // for (int i = 1; i < n; i++)
//     // {
//     //     cout << "for i=" << i << endl;
//     //     cout << "before y=" << y << endl;
//     //     y = y * (count);
//     //     count + z;
//     //     cout << "after y=" << y << endl;
//     // }
//     // cout << y << endl;

//     // optimized
//     cout << x << "^" << n << "=";
//     if (n == 0)
//         cout << 1;
//     exit;
//     if (x == 0)
//         cout << 0;
//     exit;
//     if (x == 1)
//         cout << 1;
//     exit;
//     if (x == -1 && n % 2 == 0)
//         cout << 1;
//     exit;
//     if (x == -1 && n % 2 != 0)
//         cout << -1;
//     exit;
//     long long power = n;
//     double result = 1;

//     if (power < 1)
//     {
//         x = 1 / x;
//         power = -power;
//     }

//     while (power > 0)
//     {
//         if (power % 2 == 1)
//         {
//             result *= x;
//         }
//         x = x * x;
//         power /= 2;
//     }
//     cout << result << endl;
// }

// int maxProfit(vector<int> &prices)
// {
//     // //brute force
//     // int maxDiff = INT_MIN;
//     // int n = prices.size();
//     // int st, end, diff;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << "for i=" << i << endl;
//     //     for (int j = i + 1; j < n; j++)
//     //     {
//     //         cout << "for j=" << j << endl;
//     //         cout << "prices[" << i << "]=" << prices[i] << endl;
//     //         cout << "prices[" << j << "]=" << prices[j] << endl;
//     //         if (prices[i] < prices[j])
//     //         {
//     //             diff = prices[j] - prices[i];
//     //             cout << "diff=" << diff << endl;
//     //             maxDiff = max(maxDiff, diff);
//     //             cout << "maxDiff=" << maxDiff << endl;
//     //         }
//     //         cout << endl;
//     //     }
//     // }
//     // if (maxDiff < 0)
//     //     return 0;
//     // return maxDiff;

//     int bestBuy = prices[0];
//     int maxProfit = 0;
//     for (int i = 1; i < prices.size(); i++)
//     {
//         if (prices[i] < bestBuy)
//         {
//             bestBuy = min(bestBuy, prices[i]);
//         }
//         maxProfit = max(maxProfit, prices[i] - bestBuy);
//     }
//     return maxProfit;
// }

// int main()
// {
//     // patterns
//     // squarePattern();
//     // squareStarPattern();
//     // charSquarePattern();
//     // squareStarPattern2();
//     // charSquarePattern2();
//     // starTrianglePattern2();
//     // TrianglePattern2();
//     // mixPractice();

//     // functions
//     //  cout << checkPrimeNumm(18);
//     //  finnaciSeries(7);

//     // binary number system
//     //  decToBin(10);
//     //  BinaryToDec(1001);

//     // bitwise
//     // cout << (6 & 10) << endl;
//     // cout << (6 | 10) << endl;
//     // cout << (6 ^ 10) << endl;
//     // cout << (10 << 2) << endl;
//     // cout << (10 >> 1) << endl;
//     // reverseInteger(1324567);

//     // arrays
//     // int arr[] = {32, 123, -20, 4433, 43, -500, -12, 4, 32, -10, -100,5000};
//     // int length = sizeof(arr) / sizeof(arr[0]);
//     // smallestArrayElement(arr, length);

//     // vectors
//     // vector<int> v = {1, 2, 3, 4, 5};
//     // subArray(v); //Lc 53
//     // noofSubarraysAndMaxSum();

//     // pair sum
//     // vector<int> v = {2, 7, 8, 10, 11, 15};
//     // int target = 9;
//     // pairSum(v, target);

//     // MAJORITY ELEMENT //lc-163
//     // vector<int> v = {2, 2, 1, 1, 1, 2, 2};
//     // vector<int> v = {3, 2, 3};
//     // majorityElement(v);

//     // power//LC - 50
//     // power(2, -4);

//     // stockProbel
//     vector<int> v = {7,6,4,3,1};
//     cout << "The max profit is " << maxProfit(v) << endl;
//     return 0;
// }

#include<iostream>
int x;

int main()
{
    bool b=1;
    std::cout << b;
    return 0;
}