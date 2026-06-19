// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    bool prime = true;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            prime = false;
            exit;
        };
    }
    return prime;
}

void primeNumbers(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (i % 2 != 0 && isPrime(i))
        {
            cout << i << " ";
        }
    }
}

void fibonacciSeries(int n)
{
    int a = 0;
    int b = 1;
    int c;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}

int recFibonacciSeries(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return recFibonacciSeries(n - 1) + recFibonacciSeries(n - 2);
}

int decToBin(int n)
{
    int pow = 1, ans = 0, rem = 0;
    while (n > 0)
    {
        rem = n % 2;
        n = n / 2;
        ans = ans + rem * pow;
        pow = pow * 10;
    }
    return ans;
}

int binToDec(int n)
{
    int pow = 1, ans = 0, rem = 0;
    while (n > 0)
    {
        rem = n % 10;
        n = n / 10;
        ans = ans + rem * pow;
        pow = pow * 2;
    }
    return ans;
}

int printSmallestNumber(int a[], int size)
{
    int smallest = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        smallest = min(smallest, a[i]);
        // cout << smallest << " ";
    }

    return smallest;
}
int printlargestNumber(int a[], int size)
{
    int largest = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        largest = max(largest, a[i]);
        // cout << largest << " ";
    }

    return largest;
}

int linearSearch(int a[], int size, int tar)
{
    int largest = INT_MIN;
    int smallest = INT_MAX;
    int sum = 0;
    int prod = 1;
    for (int i = 0; i < size; i++)
    {

        // if (tar == a[i])
        // {
        //     return i;
        // }
        // sum product and swap largest and smallest
        sum += a[i];
        prod *= a[i];
        smallest = min(a[i], smallest);
        largest = max(a[i], largest);
        if (largest == a[i])
        {
            a[i] = smallest;
        }
        if (smallest == a[i])
            a[i] = largest;
    }
    cout << "sum = " << sum << endl;
    cout << "prod = " << prod << endl;
    cout << "smallest = " << smallest << endl;
    cout << "largest = " << largest << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    return -1;
}

void printUniqueValue()
{
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
    {
        bool found = false;
        for (int j = 0; j < 3; j++)
        {

            if (a[i] == b[j])
            {
                found = true;
                continue;
            }
        }
        if (!found)
            cout << b[i] << endl;
    }
}

int uniqueValue(vector<int> &v)
{
    int ans = -1;
    for (int i = 0; i < v.size(); i++)
    {
        bool found = false;
        // cout << v[i] << " = ";
        for (int j = 0; j < v.size(); j++)
        {

            if (i != j && v[i] == v[j])
            {
                found = true;
                break;
            }
            // cout << v[j] << " ";
        }
        // cout << endl;
        if (!found)
            ans = v[i];
    }
    return ans;
}

void subArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            cout << v[j];
        }
        cout << endl;
    }
}

void maxSubarraySum(vector<int> v)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int currSum = 0;
        for (int j = i; j < v.size(); j++)
        {
            // cout << v[j] << " ";
            currSum += v[j];
            maxSum = max(maxSum, currSum);
        }
        // cout << endl;
    }
    cout << "maxSum " << maxSum << endl;
}

void maxSubarraySumByKadane(vector<int> v)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        currSum += v[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "maxSum = " << maxSum << endl;
}

void pairsum(vector<int> &v, int tar, pair<int, int> &p)
{
    int sum = 0;
    int st = 0, end = v.size() - 1;
    while (st < end)
    {
        sum = v[st] + v[end];
        if (sum == tar)
        {
            p.first = v[st];
            p.second = v[end];
            return;
        }
        else if (sum > tar)
            end--;
        else if (sum < tar)
            st++;
    }
}

// i.e max number of repeating elements
// O(n2)
void majorityElement(vector<int> &v, int &maxCount, pair<int, int> &p)
{

    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int freq = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                freq++;
                count = freq;
                if (maxCount < count)
                {
                    // cout << "maxCount = " << maxCount << endl;
                    // cout << "count = " << count << endl;

                    p.second = j;
                }
                maxCount = max(maxCount, freq);
                p.first = maxCount;
            }
        }
    }
}

void sort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}
// as per def of majority element
// O(n)
int majorityElementOptimized(vector<int> &v)
{
    int majorityElement = -1;
    int count = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
            count++;
        if (count >= v.size() / 2)
        {
            cout << v[i] << endl;
            return count;
        }
    }
    return majorityElement;
}

double power(double n, int m)
{
    // chcek corner cases
    if (m < 1)
    {
        m = m * -1;
        n = 1 / n;
    }
    double k = n;
    for (int i = 1; i <= m; i++)
    {
        n = n * k;
        // cout << n << " ";
    }
    return n;
}

// O(n2)
int maxProfit(vector<int> &v)
{
    int profit = 0;
    // vector<int> vec = {7, 1, 5, 3, 6, 4};
    // vector<int> vec = {7, 6, 4, 3, 1};
    // vector<int> vec = {1,2};
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            profit = max(profit, v[j] - v[i]);
        }
    }

    return profit;
}

int maxProfitOptimize(vector<int> &v)
{
    int mini = INT_MAX;
    int maxi = 0;
    int profit = 0;
    // 2 4 1
    for (int i = 0; i < v.size(); i++)
    {
        mini = min(mini, v[i]);
        profit = max(profit, v[i] - mini);
    }
    return profit;
}

int maxWater(vector<int> &v)
{
    int st = 0, end = v.size();
    int vol = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            int w = j - i;
            int h = min(v[i], v[j]);
            vol = max(vol, w * h);
        }
    }
    return vol;
}
int maxWaterOptimize(vector<int> &v)
{
    int st = 0, end = v.size() - 1;
    int vol = 0;
    while (st < end)
    {
        int w = end - st;
        int h = min(v[end], v[st]);
        vol = max(h * w, vol);
        if (v[st] < v[end])
            st++;
        else
            end--;
    }
    return vol;
}

void arrayProductExceptItself(vector<int> &v)
{
    int prod = 1;
    for (int i : v)
    {
        prod *= i;
    }
    for (int i : v)
    {
        cout << prod / i << " ";
    }
}

int binarySearch(vector<int> &v, int tar)
{
    int st = 0;
    int end = v.size() - 1;
    while (st <= end)
    {

        int mid = st + (end - st) / 2;
        if (v[mid] == tar)
            return mid;
        else if (tar > v[mid])
            st = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int recBinarySearch(vector<int> &v, int tar, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (v[mid] > tar)
            return recBinarySearch(v, tar, st, mid - 1);
        else if (v[mid] < tar)
            return recBinarySearch(v, tar, mid + 1, end);
        else
            return mid;
    }
    else
        return -1;
}

int searchInRotatedSortedArray(vector<int> &v, int tar)
{
    int st = 0, end = v.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (v[mid] == tar)
            return mid;
        else if (v[st] <= v[mid]) // left  sorted
        {
            if (v[st] <= tar && tar <= v[mid])
                end = mid - 1;
            else
                st = mid + 1;
        }
        else
        {
            if (v[mid] <= tar && tar <= v[end])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int peakValueIntheMountain(vector<int> &v)
{
    int st = 0, end = v.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        // mid-1 and mid+1 -> may break at boundary conditions
        // but mountains peak connot be at boundaries j=hence solyion is correct
        if (v[mid - 1] < v[mid] && v[mid] > v[mid + 1])
            return v[mid];
        else if (v[mid - 1] > v[mid])
            end = mid - 1;
        else
            st = mid + 1;
    }
    return -1;
}

int peakValueIntheMountainOptimized(vector<int> &v)
{
    int st = 0, end = v.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (v[mid] < v[mid + 1])
            st = mid + 1;
        else
            end = mid;
    }
    return v[st];
}

int uniqueElement(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (i != j && v[i] == v[j])
            {
                count++;
                break;
            }
        }
        if (count == 0)
            return v[i];
    }
    return -1;
}

int uniqueElementBetter(vector<int> &v)
{
    for (int i = 1; i < v.size() - 1; i++)
    {
        if (v[i - 1] != v[i] && v[i] != v[i + 1])
            return v[i];
    }
    return -1;
}

void reverseChar(vector<char> &c)
{
    int st = 0;
    int end = c.size() - 1;
    while (st < end)
    {
        char temp = c[st];
        c[st] = c[end];
        c[end] = temp;
        st++;
        end--;
    }
}

void reverseString()
{
    
}
int main()
{
    // Write C++ code here
    // primeNumbers(20);

    // fibonacciSeries(8);
    // for (int i = 0; i < 8; i++)
    // {
    //

    //     cout << recFibonacciSeries(i) << " ";
    // }

    // cout<<decToBin(36)<<endl;
    // cout<<binToDec(101010)<<endl;

    // int a[] = {23, 54, 5, 62, -65, 324, 26};
    // int size = sizeof(a) / sizeof(a[0]);
    // cout << printSmallestNumber(a, size) << endl;
    // cout << printlargestNumber(a, size) << endl;

    // int a[] = {23, 54, 23, 65, 8798, 45, 3};
    // int length = sizeof(a) / sizeof(a[0]);
    // cout << linearSearch(a, length, 65) << endl;

    // printUniqueValue();

    // vector<int> v = {1, 2, 1, 3, 2};
    // cout << uniqueValue(v) << endl;

    // vector<int> v = {1, 2, 3, 4, 5};
    // subArray(v);
    // cout << "Helo" << endl;

    // vector<int> v = {3, -4, 5, 4, -1, 7, -8};
    // // maxSubarraySum(v);
    // maxSubarraySumByKadane(v);

    // vector<int> v = {2, 7, 11, 15};
    // int tar = 8;
    // pair<int, int> p = {-1,-1};
    // pairsum(v, tar, p);
    // cout << " Hello " << p.first << " " << p.second << endl;

    // vector<int> v = {1, 2, 2, 0, 1, 1};
    // vector<int> v = {2, 34, 67, 2, 67, 65, 32, 67};
    // int maxCount = 0;
    // pair<int, int> p = {0, 0};
    // majorityElement(v, maxCount, p);
    // // cout << "maxCount = " << maxCount << endl;
    // cout << "element " << v[p.second] << " occurs " << p.first << " times" << endl;

    // vector<int> v = {1, 2, 2, 0, 1, 1};
    // cout << majorityElementOptimized(v) << endl;
    // sort(v);
    // for (int i : v)
    // {
    //     cout << i << " ";
    // }

    // cout << power(2, -1) << endl;

    // vector<int> vec = {7, 1, 5, 3, 6, 4};
    // vector<int> vec = {7, 6, 4, 3, 1};
    // vector<int> vec = {1, 2};
    // vector<int> vec = {2, 4, 1};
    // cout << maxProfit(vec);
    // cout << maxProfitOptimize(vec);

    // vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // // cout << maxWater(vec) << endl;
    // cout << maxWaterOptimize(vec) << endl;

    // vector<int> vec = {1, 2, 3, 4};
    // arrayProductExceptItself(vec);

    // vector<int> vec = {-1, 0, 3, 4, 5, 9, 12}; // odd
    // int tar = 12;
    // // cout << vec[binarySearch(vec, tar)] << endl;
    // cout << vec[recBinarySearch(vec, tar, 0, vec.size() - 1)] << endl;

    // vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    // int tar = 0;
    // cout << searchInRotatedSortedArray(vec, tar) << endl;

    // vector<int> vec = {-1, 0, 3, 8, 9, 50};
    // // cout << peakValueIntheMountain(vec) << endl;
    // cout << "Hello";
    // cout << peakValueIntheMountainOptimized(vec) << endl;

    // vector<int> v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    // // vector<int> v = {3, 3, 7, 7, 10, 11, 11};
    // // cout << uniqueElement(v) << endl;
    // cout << uniqueElementBetter(v) << endl;

    // strings
    vector<char> c = {'S', 'W', 'A'};
    reverseChar(c);
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}