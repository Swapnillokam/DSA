#include <iostream>

using namespace std;

void print(int n)
{
    if (n == 0)
        return;
    print(n - 1);
    cout << n << endl;
}

void printEven(int n)
{
    if (n % 2 == 1)
        n = n - 1;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    printEven(n - 2);
    cout << n << endl;
}

int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return n * fact(n - 1);
}

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int pow(int m, int n)
{
    if (n == 0)
        return 1;
    return m * pow(m, n - 1);
}

int sumOfSquareOfN_NaturalNumber(int n)
{
    if (n == 1)
        return 1;
    return (n * n) + sumOfSquareOfN_NaturalNumber((n - 1));
}

int nthFibonnaciSeries(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return nthFibonnaciSeries(n - 1) + nthFibonnaciSeries(n - 2);
}

// LC - q10 --- gives TLE
int climbingStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return climbingStairs(n - 1) + climbingStairs(n - 2);
}

int fibonnaciSeriesWithLoop(int n)
{
    if (n < 2)
        return n;
    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

/* int gcdRecursion(int a, int b)
{
    if (b == 0)
        return a;
    gcdRecursion(b, a % b);
} */

void recArray(int a[], int size)
{
    if (size <= 0)
        return;
    recArray(a, size - 1);
    cout << a[size - 1] << " ";
}

int recArraySum(int a[], int size)
{
    if (size == 1)
        return a[size - 1];
    return a[size - 1] + recArraySum(a, size - 1);
}

int recMinimumElementArray(int a[], int size)
{
    if (size == 1)
        return a[size - 1];
    return min(a[size - 1], recMinimumElementArray(a, size - 1));
}

/* bool checkStringPalindrome(string s)
{
    int st = 0;
    int end = s.length() - 1;
    while (st <= end)
    {
        if (s[st] != s[end])
            return false; 
        return true;
    }
} */

bool recCheckStringPalindrome(string s, int st, int end)
{
    if (s[st] <= s[end])
        return true;
    if (s[st] != s[end - 1])
        return false;
    return recCheckStringPalindrome(s, st++, end--);
}

int recVowel(string s, int end)
{
    if (end < 0)
    {
        return 0;
    }

    if (s[end] == 'a' || s[end] == 'A' || s[end] == 'e' || s[end] == 'E' || s[end] == 'i' || s[end] == 'I' || s[end] == 'o' || s[end] == 'O' || s[end] == 'u' || s[end] == 'U')
    {
        return 1 + recVowel(s, end - 1);
    }
    return recVowel(s, end - 1);
}

string recReverseString(string s, int end)
{
    if (end < 1)
        return "";
    return s[end - 1] + recReverseString(s, end - 1);
}

// try again
string recReverseString2(string s, int st, int end)
{
    if (st >= end)
        return s;
    char c = s[st];
    s[st] = s[end];
    s[end] = c;
    return recReverseString2(s, st + 1, end - 1);
}

char toLower(char &c)
{
    if (int(c) >= 65 && int(c) <= 90)
    {
        // cout << char(int(c) + 32) << endl;
        return char(int(c) + 32);
    }
    else
        return c;
}

string recToLowerString(string &s, int end)
{
    if (end < 0)
        return "";
    return recToLowerString(s, end - 1) + toLower(s[end]);
}

int recLinearSumTarget(int a[], int end, int target)
{
    if (end < 0)
        return -1;
    if (a[end] == target)
        return end;
    return recLinearSumTarget(a, end - 1, target);
}
int recTwoPointerSumTarget(int a[], int st, int end, int target)
{
    if (st >= end)
        return -1;
    if (a[st] == target)
        return st;
    if (a[end] == target)
        return end;
    return recTwoPointerSumTarget(a, st++, end - 1, target);
}

/* int recBinarySumTarget(int a[], int st, int end, int target)
{
    if (st > end)
        return -1;

    int mid = (st + (end - st) / 2);

    if (a[mid] == target)
        return mid;

    if (target > a[mid])
        return recBinarySumTarget(a, mid + 1, end, target);

    if (target < a[mid])
        return recBinarySumTarget(a, st, mid - 1, target);
} */

int main()
{
    // cout << "Enter number\n";
    // int n;
    // cin >> n;
    // cout << fact(5) << endl;
    // print(n);
    // printEven(n);
    // cout << sum(5) << endl;
    // cout << pow(4, 3) << endl;
    // cout << sumOfSquareOfN_NaturalNumber(2) << endl;
    // cout << nthFibonnaciSeries(6) << endl;
    cout << fibonnaciSeriesWithLoop(8) << endl;
    // cout << gcdRecursion(15, 120) << endl;

    int arr[] = {7, 2, 4, -1, -6};
    // recArray(arr, 6);
    // cout << recArraySum(arr, 6) << endl;
    // cout << recMinimumElementArray(arr, 6) << endl;
    // cout << checkStringPalindrome("naman") << endl;
    // cout << recCheckStringPalindrome("mo", 0, 2) << endl;
    // cout << recVowel("aeiou", 4) << endl;
    // cout << recReverseString("linpaws", 7) << endl;
    // cout << recReverseString2("linpaws", 0, 6) << endl;

    // cout << (int)('A') << endl;
    // // cout << (char)(97) << endl;
    // cout << (int)('Z') << endl;

    // tried for verification
    char c = 'Z';
    // cout << char(tolower(c)) << endl;   inbuilt
    //  toLower(c);
    // cout << char(toLower(c)) << endl; // userdefined

    // string s = "LINPAWS";
    // cout << recToLowerString(s, 6) << endl;

    // int a[] = {1, 5, 7};
    // int target = 5;
    // cout << "target is at index " << recLinearSumTarget(a, 4, target) << endl;
    // cout << "target is at index " << recTwoPointerSumTarget(a, 0, 4, target) << endl;
    // int a[] = {3, 8, 11, 15, 20, 22};
    // int target = 15;
    // cout << "target is at index " << recBinarySumTarget(a, 0, 4, target) << endl;

    return 0;
}