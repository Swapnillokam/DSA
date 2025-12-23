#include <iostream>
using namespace std;

int DecToBinary()
{
    int decNum, rem, ans, power;
    cout << "Enter the decimal number\n";
    cin >> decNum;
    power = 1;
    ans = 0;

    while (decNum > 0)
    {
        rem = decNum % 2;
        decNum = decNum / 2;
        ans = ans + rem * power;
        power = power * 10; // we have to convert from decimal to binary hence multiplying by 10
    }
    return ans;
}

int BinaryToDec()
{
    int binNum, rem, ans, power;
    cout << "\nEnter the binary number\n";
    cin >> binNum;
    power = 1; // 2^0
    ans = 0;
    while (binNum > 0)
    {
        rem = binNum % 10;
        ans += rem * power;
        binNum = binNum / 10;
        power *= 2;
    }
    return ans;
}

int main()
{
    int decToBinary = DecToBinary();
    cout << "The binary number for the given decimal number " << decToBinary << endl;
    int binaryToDec = BinaryToDec();
    cout << "The decimal number for the given binary number " << binaryToDec << endl;
    return 0;
}