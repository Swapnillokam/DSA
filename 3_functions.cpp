#include <iostream>
using namespace std;

void primeNum(int n)
{
   bool isPrime = true;

   for (int i = 2; i < n; i++)
   {
      if ((n % i == 0))
      {
         isPrime = false;
         break;
      }
   }

   if (!isPrime)
   {
      cout << ("The number is not prime\n");
   }
   else
   {
      cout << "The number is prime\n";
   }
}

void printPrimeNum(int n)
{
   bool isPrime = true;
   for (int i = 2; i < n; i++)
   {
      if (n % i == 0)
      {
         isPrime = false;
         break;
      }
      else
      {
         cout << i << " ";
      }
   }
}

void fibonacciSeries(int n)
{
   int sum = 0;
   for (int i = 0; i <= n; i++)
   {
      sum += i;
      cout << sum << " ";
   }
}
int main()
{
   int n;
   cout << "Enter any number\n";
   cin >> n;
   primeNum(n);

   printPrimeNum(n);   //wrong
   fibonacciSeries(n); //wrong
   return 0;
}