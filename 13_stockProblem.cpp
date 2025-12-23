#include <iostream>
#include <vector>
using namespace std;

// bruteforce
double myPowSimple(double x, int n)
{
    double prod = 1;
    for (int i = 1; i <= n; i++)
    {
        prod *= x;
    }
    return prod;
}

// leetcode 50 - Power(x,n)
// Binary exponentiation
double myPow(double x, int n)
{
    // handling corner cases
    if (n == 0)
        return 1;
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    if (x == -1 && n % 2 == 0)
        return 1;
    if (x == -1 && n % 2 != 0)
        return -1;

    long binForm = n;
    double ans = 1;

    // if n is negative
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }

    while (binForm > 0)
    {
        if (binForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }
    return ans;
}

// leetcode 121 - Best time to buy and sell stock
int maxProfit(vector<int> &prices)
{
    int bestBuy = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++)
    {

        if (bestBuy < prices[i])
        {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(prices[i], bestBuy);
        return bestBuy;
    }
    return 0;
}

int main()
{
    cout << "The power of the given number using bruteforce method is " << myPowSimple(4, 2) << endl;
    // cout << "The power of the given number is " << myPow(2, 4) << endl;

    vector<int> vec = {7, 1, 5, 3, 6, 4};

    // cout << "The maxProfit will be when the buyPrice is " << maxProfit(vec) << endl;
    return 0;
}