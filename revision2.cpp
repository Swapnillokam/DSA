#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <map>
using namespace std;

void print2DArrays()
{
    int a[3][3];
    cout << "Enter the array values" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "The array values are: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void _2DlinearSearch(int a[][3], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // cout << a[i][j] << " ";
            if (a[i][j] == target)
            {
                cout << "a[" << i << "][" << j << "]" << " = " << target << endl;
            }
        }
    }
}

void maxRowSum2D(int a[][3], int rows, int cols)
{
    int maxRowSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum = sum + a[i][j];
        }
        maxRowSum = max(maxRowSum, sum);
    }
    cout << "The max row sum is " << maxRowSum << endl;
}

void sumOfTwoElements2(vector<int> &v, int target)
{
    vector<int> ans;
    unordered_map<int, int> m;

    for (int i = 0; i < v.size(); i++)
    {
        int first = v[i];
        int sec = target - first;
        if (m.find(sec) != m.end())
        {
            ans.push_back(m[sec]);
            ans.push_back(i);
            break;
        }
        m[first] = i;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void findMissingAndRepeatingValues(vector<vector<int>> &v)
{
    set<int> s;
    vector<int> ans;
    int actualSum = 0, expectedSum = 0, a;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            actualSum += v[i][j];
            count++;
            if (s.find(v[i][j]) != s.end())
            {
                a = v[i][j];
                ans.push_back(v[i][j]);
            }
            s.insert(v[i][j]);
        }
    }
    expectedSum = count * (count + 1) / 2;
    cout << "count = " << count << endl;
    cout << "expectedSum = " << expectedSum << endl;
    cout << "actualSum = " << actualSum << endl;
    cout << "a = " << a << endl;
    int missingValue = expectedSum + a - actualSum;
    ans.push_back(missingValue);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void findDuplicate(vector<int> &v)
{
    set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.find(v[i]) != s.end())
            cout << "duplicate value = " << v[i];
        s.insert(v[i]);
    }
}

int sumOfDiagonalsIn2dArray(vector<vector<int>> &v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (i == j || j == (v[i].size() - 1 - i))
            {
                sum += v[i][j];
            }
        }
    }
    return sum;
}

int sumOfDiagonalsIn2dArrayOptimize(vector<vector<int>> &v)
{
    int sum = 0;
    int n = v.size() - 1;
    int start = 0;
    int end = n;
    while (start <= n && end >= 0)
    {
        cout << endl;
        cout << "start is " << start << " value is " << v[start][start] << endl;
        cout << "end is " << end << " value is " << v[start][end] << endl;

        if (start != end)
            sum += v[start][start] + v[start][end];
        else if (start == end)
            sum += v[start][end];
        start++;
        end--;
    }
    return sum;
}

int searchInSortedArray(vector<vector<int>> &v, int target, int row)
{
    int end = v.size() - 1;
    int st = 0;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        // int x = v[row][mid];
        if (v[row][mid] == target)
            return mid;
        else if (target > v[row][mid])
            st = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

pair<int, int> searchIn2DSortedMatrix(vector<vector<int>> &v, int tar)
{
    int endRow = v.size() - 1;
    int stRow = 0;

    pair<int, int> result = {-1, -1};
    if (tar >= v[stRow][stRow] && tar <= v[endRow][endRow])
    {
        while (stRow <= endRow)
        {
            int midRow = (stRow + endRow) / 2;

            // int x = v[midRow][v[midRow].size() - 1];
            // int y = v[midRow][0];
            if (tar > v[midRow][v[midRow].size() - 1])
            {
                stRow = midRow + 1;
            }
            else if (tar < v[midRow][0])
            {
                endRow = midRow - 1;
            }
            else if (tar >= v[midRow][0] && tar <= v[midRow][v[midRow].size() - 1])
            {
                result.first = midRow;
                result.second = searchInSortedArray(v, tar, midRow);
                return result;
            }
        }
    }
    else
    {
        cout << "The target value " << tar << " do not exist" << endl;
        return result;
    }
}

vector<int> spiralMatrix(vector<vector<int>> &v)
{
    int rows = v.size() - 1;
    int cols = v[0].size() - 1;
    int tr = 0, br = rows;
    int lc = 0, rc = cols;
    vector<int> ans;
    while (tr <= br && lc <= rc)
    {
        // top
        for (int i = lc; i <= rc; i++)
        {
            int x = v[tr][i];
            cout << v[tr][i] << " ";
            ans.push_back(v[tr][i]);
        }
        tr++;
        // right
        for (int i = tr; i <= br; i++)
        {
            int x = v[i][rc];
            cout << v[i][rc] << " ";
            ans.push_back(v[i][rc]);
        }
        rc--;
        // bottom
        // if (br <= tr)
        {
            for (int i = rc; i >= lc; i--)
            {
                int x = v[br][i];
                cout << v[br][i] << " ";
                ans.push_back(v[br][i]);
            }
            br--;
        }
        // left
        // if (lc <= rc)
        {
            for (int i = br; i >= tr; i--)
            {
                int x = v[i][lc];
                cout << v[i][lc] << " ";
                ans.push_back(v[i][lc]);
            }
            lc++;
        }
    }
    return ans;
}

vector<int> sumOfTwoElementsRev(vector<int> &v, int target)
{
    vector<int> ans;
    // brtute force appraoch

    /* for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            int sum = v[i] + v[j];
            if (target == sum)
            {
                ans.push_back(v[i]);
                ans.push_back(v[j]);

                cout << "v[" << i << " = ]" << v[i] << endl;
                cout << "v[" << j << " = ]" << v[j] << endl;
                return ans;
            }
        }
    } */

    // 0(nlogn)
    /*     sort(v.begin(), v.end());
        int st = 0;
        int end = v.size() - 1;
        while (st < end)
        {
            int sum = v[st] + v[end];
            if (sum == target)
            {
                ans.push_back(v[st]);
                ans.push_back(v[end]);

                cout << v[st] << endl;
                cout << v[end] << endl;
                return ans;
            }
            else if (sum > target)
            {
                end--;
            }
            else if (sum < target)
            {
                st++;
            }
        }
        */

    // optimized 0(n)
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        int first = v[i];
        int sec = target - first;
        if (m.find(sec) != m.end())
        {
            ans.push_back(sec);
            ans.push_back(first);
            cout << first << endl;
            cout << sec << endl;
            break;
        }
        m[first] = i;
    }

    return ans;
}

void threeSum(vector<int> &v)
{
    // brute force 0(n3*logn)
    /* set<vector<int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                vector<int> triplet;
                int a = v[i];
                int b = v[j];
                int c = v[k];
                if (v[i] + v[j] + v[k] == 0)
                {
                    triplet.push_back(v[i]);
                    triplet.push_back(v[j]);
                    triplet.push_back(v[k]);
                    sort(triplet.begin(), triplet.end());
                    s.insert(triplet);
                }
            }
        }
    }
    for (auto v : s)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    } */

    // better
    /* set<vector<int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        unordered_map<int, int> m;
        int target = -v[i];
        for (int j = i + 1; j < v.size(); j++)
        {
            int second = v[j];
            int third = target - second;
            if (m.find(third) != m.end())
            {
                vector<int> triplets = {v[i], second, third};
                sort(triplets.begin(), triplets.end());
                s.insert(triplets);
            }
            m[second] = j;
        }
    }
    for (auto v : s)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    } */

    // optimized
    sort(v.begin(), v.end());
    set<vector<int>> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = v.size() - 1;
        while (j < k)
        {
            int sum = v[i] + v[j] + v[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else if (sum == 0)
            {
                vector<int> trip = {v[i], v[j], v[k]};
                sort(trip.begin(), trip.end());
                ans.insert(trip);
                j++;
                k--;
                while (j < k && v[j] == v[j - 1])
                {
                    j++;
                }
            }
        }
    }

    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> fourSum(vector<int> &v, int target)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (j > i + 1 && v[j] == v[j - 1])
                continue;
            int k = j + 1;
            int l = v.size() - 1;
            while (k < l)
            {
                int sum = v[i] + v[j] + v[k] + v[l];
                if (sum > target)
                    l--;
                else if (sum < target)
                    k++;
                else if (sum == target)
                {
                    vector<int> quadLet = {v[i], v[j], v[k], v[l]};
                    s.insert(quadLet);
                    l--;
                    k++;
                    while (k < l && v[k] == v[k - 1])
                    {
                        k++;
                    }
                    while (k < l && v[l] == v[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }
    for (auto i : s)
    {
        ans.push_back(i);
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return ans;
}

void printSubArray(vector<int> &v, int t)
{
    // brute force 0(n2)
    /* int sum = INT_MIN;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            int total = 0;
            for (int k = i; k <= j; k++)
            {
                cout << v[k];
                total += v[k];
            }
            if (t == total)
                count++;
            sum = max(sum, total);
            cout << " ";
        }
        cout << endl;
    }
    cout << "Sum = " << sum << endl;
    cout << "count = " << count << endl; */

    // 0(n2)
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (t == sum)
            {
                count++;
            }
        }
    }
    cout << "count = " << count << endl;
}

bool isPrime(int n)
{
    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

void primeNumbers(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}

void digits(int n)
{
    cout << "shortcut to find no.of digits " << int(log10(n) + 1) << endl;
    int lastDigit, count = 0, sum = 0;
    while (n > 0)
    {
        lastDigit = n % 10;
        cout << lastDigit << " ";
        sum += lastDigit;
        count++;
        n = n / 10;
    }
    cout << endl
         << "no.of digits " << count << endl;
    cout << "sum.of digits " << sum << endl;
}

bool checkArmStrong(int n)
{
    int sum = 0;
    int num = n;
    while (n > 0)
    {
        int lastDigit = n % 10;
        sum += lastDigit * lastDigit * lastDigit;
        n = n / 10;
    }
    if (num == sum)
        return true;
    return false;
}

int GCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a >= b)
        {
            a = a % b;
        }
        else if (b > a)
        {
            b = b % a;
        }
    }
    if (b == 0)
        return a;
    else
        return b;
}
int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int reverseNumber(int n)
{
    int reverseNumber = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        reverseNumber = reverseNumber * 10 + lastDigit;
        n = n / 10;
    }
    return reverseNumber;
}

bool checkPalindrome(int n)
{
    if (reverseNumber(n) == n)
        return true;
    return false;
}

string stringCompression(vector<char> &ch)
{
    string s = "";
    for (int i = 0; i < ch.size(); i++)
    {
        int count = 1;
        while (i + 1 < ch.size() && ch[i] == ch[i + 1])
        {
            count++;
            i++;
        }
        s += ch[i];
        if (count > 1)
            s += to_string(count);
    }

    return s;
}

string reverseWordsInString(string s)
{
    string ans = "";
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        string words = "";
        while (i < s.length() && s[i] != ' ')
        {
            words += s[i];
            i++;
        }
        reverse(words.begin(), words.end());
        ans += words + " ";
    }
    return ans;
}

bool stringPalindrome(string s)
{
    int st = 0;
    int end = s.length() - 1;
    while (st <= end)
    {
        if (s[st] != s[end])
            return false;
        st++;
        end--;
    }
    return true;
}

string formatString(string s)
{
    string formattedString = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            formattedString += tolower(s[i]);
        }
    }
    return formattedString;
}

string removeAllPartOccurrencesInString(string &s, string &part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

void permutationInString(string s)
{
    set<string> permutations;
    for (int i = 0; i < 6; i++)
    {
        next_permutation(s.begin(), s.end());
        permutations.insert(s);
    }
    for (auto v : permutations)
    {
        cout << v << " ";
    }
}

void fibonnaciSeries(int n)
{
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
        cout << b << " ";
    }
}

void sortArray(int a[])
{

    int n = sizeof(a) / sizeof(a[0]);
    cout << "n = " << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int uniqueValue(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                count++;
            }
        }
        if (count == 1)
            return v[i];
    }
    return -1;
}

void highFrequencyElement(vector<int> &v)
{
    // unoreedered map
    /* unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        int first = v[i];

        if (m.find(first) != m.end())
        {
            // cout<<m[first] --> gives value of m[first]
            m[first] = m[first] + 1;
        }
        else
            m[first] = 1;
    }

    int maxCount = INT_MIN;
    int element;
    for (auto i : m)
    {
        cout << i.first << " : " << i.second << endl;
        if (i.second > maxCount)
        {
            maxCount = i.second;
            element = i.first;
        }
    }
    cout << "Highest frequesncy is " << maxCount << " and value is " << element << endl; */

    // orderred map
    map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        int first = v[i];

        if (m.find(first) != m.end())
        {
            // cout<<m[first] --> gives value of m[first]
            m[first] = m[first] + 1;
        }
        else
            m[first] = 1;
    }

    int maxCount = INT_MIN;
    int element;
    for (auto i : m)
    {
        cout << i.first << " : " << i.second << endl;
        if (i.second > maxCount)
        {
            maxCount = i.second;
            element = i.first;
        }
    }
    cout << "Highest frequesncy is " << maxCount << " and value is " << element << endl;
}

void myPow(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    double num = x;
    int i = 1;

    while (i < n)
    {
        x = x * num;
        i++;
    }
    cout << "x^n = " << x << endl;
}

int maxProfit(vector<int> &v)
{
    int maxProfit = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                int diff = v[j] - v[i];
                maxProfit = max(maxProfit, diff);
            }
        }
    }
    return maxProfit;
}

int mostWater(vector<int> &v)
{
    int maxVol = INT_MIN;
    // brute force
    /* for (int i = 0; i < v.size(); i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            if (j > i)
            {
                int width = j - i;
                int height = min(v[i], v[j]);
                maxVol = max(maxVol, height * width);
            }
        }
    } */

    // two pointer
    int st = 0;
    int end = v.size() - 1;
    while (st < end)
    {
        int width = end - st;
        int height = min(v[st], v[end]);
        maxVol = max(maxVol, width * height);
        v[st] < v[end] ? st++ : end--;
    }

    return maxVol;
}

void arrayProduct(vector<int> v)
{
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        int p = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (i != j)
            {
                p *= v[j];
            }
        }
        ans.push_back(p);
    }
    for (auto p : ans)
    {
        cout << p << " ";
    }
}

int rotatedSortedArray(vector<int> vec, int target)
{
    int st = 0;
    int end = vec.size();
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target == vec[mid])
            return mid;
        else if (target < vec[mid] && target > vec[st])
            end = mid - 1;
        else
            st = st + 1;
    }
}

int peakIndexInMountain(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i + 1] < v[i])
            return v[i];
    }
}

int factorial(int n)
{
    if (n == 1 || n == 0)
        return n;
    return n * factorial(n - 1);
}

void stringPermutaion(string s)
{
    sort(s.begin(), s.end());
    do
    {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
}
int main()
{
    // print2DArrays();

    //_2DlinearSearch and maxRowSum2D
    /*  int a[4][3] = {
         {1, 2, 3},
         {4, 5, 6},
         {7, 8, 9},
         {10, 11, 12}};
     // _2DlinearSearch(a, 4, 3, 12);
     // maxRowSum2D(a, 4, 3); */

    // sumOfTwoElements2
    /* vector<int> v = {5, 2, 11, 7, 15};
    int target = 9;
    sumOfTwoElements2(v, target); */

    // findMissingAndRepeatingValues
    /* vector<vector<int>> v1 = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}};
    findMissingAndRepeatingValues(v1); */

    // vector<int> v3 = {1, 3, 4, 2, 2};
    // findDuplicate(v3);

    // sum of diagonals of 2d array
    // cout << "Sum of Diagoanls of the 2d is " << sumOfDiagonalsIn2dArray(v1) << endl;
    // cout << "Sum of Diagoanls of the 2d in optimized way " << sumOfDiagonalsIn2dArrayOptimize(v1) << endl;

    // searchIn2DSortedMatrix
    /*  vector<vector<int>> v5 = {
         {1, 3, 5, 7},
         {10, 11, 16, 20},
         {23, 30, 34, 60}};

     int tar = 34;
     pair<int, int> result = searchIn2DSortedMatrix(v5, tar);
     cout << "Hello " << v5[result.first][result.second] << endl; */

    // spiralMarix
    /* vector<vector<int>> v8 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    spiralMatrix(v8); */

    // Tricky questions
    /* int x = 5;
    cout << "x++ = " << x++ << endl;
    cout << "x++ = " << x++ << endl;
    cout << "x = " << x << endl;

    int y = 5;
    cout << "++y = " << ++y << endl; */

    // sumofTwoElements
    /* vector<int> vSum = {5, 2, 11, 7, 15};
    int targetSum = 9;
    sumOfTwoElementsRev(vSum, targetSum); */

    // Three sum
    /* vector<int> v3Sum = {-1, 0, 1, 2, -1, -4};
    threeSum(v3Sum); */

    // Four SUm
    /* // vector<int> v4Sum = {1, 0, -1, 0, -2, 2};
    vector<int> v4Sum = {-2, -1, -1, 1, 1, 2, 2};
    int t = 0;
    fourSum(v4Sum, t); */

    // subarray
    /* vector<int> vSub = {1,1,1};
    int k = 2;
    printSubArray(vSub, k); */

    // Maths for DSA

    /* // no.of primeNumbers
    // int n = 100;
    // primeNumbers(n);

    // print digits, count of digits and sum of digits
    // digits(1001234);

    // cout << checkArmStrong(153);
    // cout << GCD(21, 28) << endl;
    // cout << LCM(6, 12) << endl;
    // cout << reverseNumber(1234) << endl;
    // cout << checkPalindrome(121) << endl; */

    // string questions
    // stringCompression
    /*  vector<char> ch = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
     // vector<char> ch = {'a', 'b'};
     // vector<char> ch = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
     cout << stringCompression(ch) << endl; */

    // reverse words in string
    /* string s = "the sky is blue";
    cout << endl
         << reverseWordsInString(s) << endl; */

    // string palindrome
    /* string s = "eye";
    cout << stringPalindrome(s); */

    /* // string s = "Ac3?e3c&a";
    // string s = "A man, a plan, a canal: Panama";
    string s = "race a car";
    string palin = formatString(s);
    cout << "formatted string " << palin << endl;
    cout << stringPalindrome(palin) << endl; */

    // check sunstring
    // string s = "axxxxyyyyb";
    // string part = "xy";
    /* string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeAllPartOccurrencesInString(s, part); */

    // check later
    // string permutation
    // permutationInString(string s);
    // permutationInString("abc");

    // fibonacci series
    // fibonnaciSeries(10);
    /* int a[] = {23, 54, 5, 62, -65, 324, 26};
    sortArray(a); */

    // unique and repeating vlues
    /* // vector<int> v = {1, 2, 1, 2, 4};
    vector<int> v = {1, 2, 2, 0, 1, 1};
    // cout << uniqueValue(v);
    highFrequencyElement(v); */

    // power(x,n)
    /* int x = 2, n = -2;
    myPow(x, n); */

    // buy sell stock problem
    /* vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(v); */

    // container with most water
    /* vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << mostWater(v); */

    // array product itself
    /* vector<int> vec = {1, 2, 3, 4};
    arrayProduct(vec); */

    /* vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << rotatedSortedArray(vec, target); */

    /* vector<int> vec = {0, 3, 8, 9, 5, 2};
    cout << peakIndexInMountain(vec); */

    // factorial
    /* int n = 5;
    // cout << factorial(n) << endl;

    string s = "abc";
    stringPermutaion(s); */

    // bruteforceappraoch for permutation
    string s = "xyz";
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            for (int k = 0; k < s.length(); k++)
            {
                if (i != j && j != k && i != k)
                    cout << s[i] << s[j] << s[k];
            }
            cout << " ";
        }
    }

    return 0;
}