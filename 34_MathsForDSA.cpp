#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

string isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        int c = n % i;
        if (n % i == 0)
        {
            return "Non Prime";
        }
    }
    return "Prime";
}

// Sieve of Eratosthenes
// leetcode-Q - 204
// Print the prime numbers
int countPrimes(int n)
{
    int count = 0;
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            count++;
            for (int j = i + i; j < n; j = j + i)
            {
                isPrime[j] = false;
            }
        }
    }
    return count;
}

// print digits, count of digits and sum of digits
void digits(int n)
{
    int count = 0;
    int sum = 0;
    cout << "The digits are ";
    // 0(logn)
    while (n != 0)
    {
        int digits = n % 10;
        count++;
        cout << digits << ",";
        sum = sum + digits;
        n = n / 10;
    }
    cout << "The count of digits is " << count << " and the sum of digits is " << sum << endl;
}

// Armstrong
void checkArmstrong(int n)
{
    int sum = 0;
    int oriNumber = n;
    while (n != 0)
    {
        int digits = n % 10;
        sum += digits * digits * digits;
        n = n / 10;
    }
    if (sum == oriNumber)
        cout << "The number is an armstrong" << endl;
    else
        cout << "The number is not an armstrong" << endl;
}

// GCD/HCF
// 0(min(a,b))
int GCD(int a, int b)
{
    int gcd = 0;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

// Euclids Algo for GCD
int GCD_ByEuclids(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}

// GCD_ByEuclids using recursion
int recursiveEuclidGCD(int a, int b)
{
    if (b == 0)
        return a;

    return recursiveEuclidGCD(b, a % b);
}

// LCM
//  a*b = GCD(a,b)*LCM(a,b)
int LCM(int a, int b)
{
    int gcd = recursiveEuclidGCD(a, b);
    return a * b / gcd;
}

// reverseNumber
// leetcode - Q 7
int reverseNumber(int x)
{
    int reversedNumber = 0;
    while (x != 0)
    {
        int digit = x % 10;
        if (reversedNumber > INT_MAX / 10 && reversedNumber < INT_MIN / 10)
            return 0;
        reversedNumber = (reversedNumber * 10) + digit;
        x = x / 10;
    }
    return reversedNumber;
}

// palindrome
bool PalindromeNumber(int n)
{
    if (reverseNumber(n) == n)
        return true;
    return false;
}

// Modulo Arithmetics
// properties
// (x + y) % m = x % m + y % m;
// (x - y) % m = x % m - y % m;
// (x.y) % m = x % m.y % m;
// ((x % m) % m....% m) = (x % m);
// leetcode Q - 850

int main()
{
    // cout << isPrime(4) << endl;
    // cout << countPrimes(10) << endl;
    // digits(3568);

    // Shortcut to find no.of digits in a numbers -> (log10(n)+1)
    // cout << int(log10(3568) + 1) << endl;

    // checkArmstrong(153);
    // cout << GCD(20, 24);
    // cout << GCD_ByEuclids(6, 12);
    // cout << recursiveEuclidGCD(20, 24);
    // cout << LCM(20, 28);
    // cout << reverseNumber(4537);
    cout << PalindromeNumber(121);

    return 0;
}