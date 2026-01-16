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

int recfibonacciSeries(int n)
{
   if (n == 1 || n == 0)
   {
      return n;
   }
   return recfibonacciSeries(n - 2) + recfibonacciSeries(n - 1);
}

void iterativeFibonacciSeries(int n)
{
   int a = 0, b = 1, c;
   if (n == 0 || n == 1)
   {
      cout << n << " ";
      return;
   }
   for (int i = 2; i <= n; i++)
   {
      c = a + b;
      a = b;
      b = c;
   }
   cout << c << " ";
}

void primeNumber(int n)
{
   for (int i = 2; i < n; i++)
   {
      bool isPrime = true;
      for (int j = 2; j < i; j++)
      {
         if (i % j == 0)
         {
            isPrime = false;
            break;
         }
      }
      if (isPrime)
      {
         cout << i << " ";
      }
   }
}

int main()
{
   // int n;
   // cout << "Enter any number\n";
   // cin >> n;
   int n = 10;
   // primeNum(n);

   // printPrimeNum(n);   // wrong
   // fibonacciSeries(n); // wrong

   // new try
   /* for (int i = 0; i < n; i++)
   {
      cout << recfibonacciSeries(i) << " ";
   } */

   // for (int i = 0; i < n; i++)
   // {
   //    iterativeFibonacciSeries(i);
   // }

   primeNumber(30);

   return 0;
}