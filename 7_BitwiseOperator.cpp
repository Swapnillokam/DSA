#include <iostream>
using namespace std;

void bitwiseOperators()
{
    int a = 4;
    int b = 8;
    cout << "(a & b) = " << (a & b) << endl;
    cout << "(6 & 10) = " << (6 & 10) << endl;
    cout << "(a | b) = " << (a | b) << endl;
    cout << "(6 | 10) = " << (6 | 10) << endl;
    cout << "(a ^ b) = " << (a ^ b) << endl;
    cout << "(6 ^ 10) = " << (6 ^ 10) << endl;
    cout << "(a << b) = " << (a << b) << endl;
    cout << "(4 << 1) = " << (4 << 1) << endl;
    cout << "(8 << 1) = " << (8 << 1) << endl;
    cout << "(10 << 2) = " << (10 << 2) << endl;
    cout << "(a >> b) = " << (a >> b) << endl;
    cout << "(10 >> 1) = " << (10 >> 1) << endl;
    cout << "(10 >> 1) = " << (10 >> 1) << endl;
    cout << "(8 >> 2) = " << (8 >> 2) << endl;
    cout << "(8 >> 1) = " << (8 >> 1) << endl;
}

// HW
// figure out of a number is power of 2 without any loop
bool powerOfTwo()
{
    int num, rem;
    cout << "Enter the number\n";
    cin >> num;
    while (num > 0)
    {
        rem = num % 2;
        if (rem != 0 && num != 1)
        {
            // cout << "Number is not power of 2\n";
            return false;
        }
        num = num / 2;
        cout << "Number is " << num << endl;
    }
    return true;
}

//HW
int reverseNumber()
{
    int num, rem, mulFactor, ans;
    ans = 0;
    mulFactor = 1;
    cout << "Enter the number\n";
    cin >> num;
    while (num > 0)
    {
        rem = num % 10;
        ans = ans * 10 + rem;
        cout << "ans = " << ans << endl;
        num = num / 10;
        cout << "num = " << num << endl;
    }
    return ans;
}

int main()
{
    // bitwiseOperators();
    // powerOfTwo() ? cout << "Number is a power of 2" : cout << "Number is not a power of 2";
    int reversedNumber = reverseNumber();
    cout << "The number after reversing is " << reversedNumber << endl;
    return 0;
}