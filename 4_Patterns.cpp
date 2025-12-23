#include <iostream>
using namespace std;

// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4 
void SquarePattern()
{
   for (int i = 1; i <= 4; i++)
   {
      for (int j = 1; j <= 4; j++)
      {
         cout << j << " ";
      }
      cout << "\n";
   }
}

// * * * * 
// * * * * 
// * * * * 
// * * * *
void starSquarePattern()
{
   for (int i = 1; i <= 4; i++)
   {
      for (int j = 1; j <= 4; j++)
      {
         cout << "*" << " ";
      }
      cout << "\n";
   }
}

// A B C D 
// A B C D 
// A B C D 
// A B C D 
void charSquarePattern()
{
   for (int i = 1; i <= 4; i++)
   {
      char ch = 'A';
      for (int j = 1; j <= 4; j++)
      {
         cout << ch << " ";
         ch++;
      }
      cout << "\n";
   }
}

// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 
// 13 14 15 16 
void SquarePattern2(int n)
{
   int a = 1;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cout << a << " ";
         a++;
      }
      cout << "\n";
   }
}

// A B C D 
// E F G H 
// I J K L 
// M N O P
void charSquarePattern2(int n)
{
   char ch = 'A';
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cout << ch << " ";
         ch++;
      }
      cout << "\n";
   }
}

// * 
// * * 
// * * * 
// * * * * 
void starTrianglePattern2(int n)
{

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= i; j++)
      {
         cout << "* ";
      }
      cout << "\n";
   }
}

// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
void TrianglePattern2(int n)
{

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= i; j++)
      {
         cout << i << " ";
      }
      cout << "\n";
   }
}

// A 
// B B 
// C C C 
// D D D D 
void charTrianglePattern2(int n)
{
   char ch = 'A';
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= i; j++)
      {
         cout << ch << " ";
      }
      ch++;
      cout << "\n";
   }
}

// A 
// A B 
// A B C 
// A B C D 
void charTrianglePattern3(int n)
{
   for (int i = 1; i <= n; i++)
   {
      char ch = 'A';
      for (int j = 1; j <= i; j++)
      {
         cout << ch << " ";
         ch++;
      }
      cout << "\n";
   }
}

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 
void TrianglePattern3(int n)
{
   for (int i = 0; i <= n; i++)
   {
      for (int j = 1; j <= i + 1; j++)
      {
         cout << j << " ";
      }
      cout << "\n";
   }
}

// reversePattern3
// 1 
// 2 1 
// 3 2 1 
// 4 3 2 1
void reversePattern3(int n)
{
   for (int i = 1; i <= n; i++)
   {
      for (int j = i; j > 0; j--)
      {
         cout << j << " ";
      }
      cout << "\n";
   }
}

// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
void floydsTrianglePattern3(int n)
{
   int count = 1;
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j >= 0; j--)
      {
         cout << count << " ";
         count++;
      }
      cout << "\n";
   }
}

// A 
// B C 
// D E F 
// G H I J 
void charfloydsTrianglePattern3(int n)
{
   char count = 'A';
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j >= 0; j--)
      {
         cout << count << " ";
         count++;
      }
      cout << "\n";
   }
}

// A 
// B A 
// C B A 
// D C B A 
void reverseCharfloydsTrianglePattern3(int n)
{
   for (int i = 0; i < n; i++)
   {
      char count = 'A' + i;
      for (int j = i; j >= 0; j--)
      {
         cout << count << " ";
         count--;
      }
      cout << "\n";
   }
}

void invertedTrianglePattern3(int n)
{
   // 1111
   //  222
   //   33
   //    4
   for (int i = 0; i < n; i++)
   {
      for (int k = 0; k < i; k++)
      {
         cout << " ";
      }
      for (int j = 0; j < (n - i); j++)
      {
         cout << (i + 1);
      }
      cout << "\n";
   }
}

void charInvertedTrianglePattern3(int n)
{
   // AAAA
   //  BBB
   //   CC
   //    D
   for (int i = 0; i < n; i++)
   {
      char ch = 'A' + i;
      for (int k = 0; k < i; k++)
      {
         cout << " ";
      }
      for (int j = 0; j < (n - i); j++)
      {
         cout << (ch);
      }
      cout << "\n";
   }
}

void pyramidPattern(int n)
{
   //    1
   //   121
   //  12321
   // 1234321
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < (n - (i + 1)); j++)
      {
         cout << " ";
      }
      for (int k = 0; k <= i; k++)
      {
         cout << (k + 1);
      }
      for (int l = i; l > 0; l--)
      {
         cout << l;
      }
      cout << "\n";
   }
}

void hollowPattern(int n)
{
   //    *
   //   * *
   //  *   *
   // *     *
   //  *   *
   //   * *
   //    *
   // top
   for (int i = 0; i < n; i++)
   { // spaces
      for (int j = 0; j < (n - (i + 1)); j++)
      {
         cout << " ";
      }
      cout << "*";
      if (i != 0)
      { // spaces
         for (int k = 0; k < (2 * i - 1); k++)
         {
            cout << " ";
         }
         cout << "*";
      }
      cout << "\n";
   }

   // bottom
   for (int i = 0; i < n - 1; i++)
   { // spaces
      for (int j = 0; j < i + 1; j++)
      {
         cout << " ";
      }
      cout << "*";
      if (i != n - 2)
      { // spaces
         for (int j = 0; j < (2 * (n - i) - 5); j++)
         {
            cout << " ";
         }
         cout << "*";
      }
      cout << "\n";
   }
}

// try this homework
void butterflyPattern(int n)
{
   // *      *
   // **    **
   // ***  ***
   // ********
   // ********
   // ***  ***
   // **    **
   // *      *
   // top
   for (int i = 0; i < n; i++)
   { // left
      for (int j = 0; j < (i + 1); j++)
      {
         cout << "*";
      }
      for (int j = 0; j < (n - (i + 1)); j++)
      {
         cout << " ";
      }

      // right
      for (int j = 0; j < n - (i + 1); j++)
      {
         cout << " ";
      }
      for (int j = 0; j < ((i + 1)); j++)
      {
         cout << "*";
      }

      cout << "\n";
   }

   // bottom
   for (int i = 0; i < 4; i++)
   {  //left
      for(int j=0;j<n-i;j++)
      {
         cout<<"*";
      }
      for(int j=0;j<(i);j++)
      {
         cout<<" ";
      }

      //right
      for(int j=0;j<(i);j++)
      {
         cout<<" ";
      }
      for(int j=0;j<(n-i);j++)
      {
         cout<<"*";
      }
      cout<<"\n";
   }

}
int main()
{
   int n = 4;
   cout<<endl<<"SquarePattern"<<endl;
   SquarePattern();
   cout<<endl<<"starSquarePattern"<<endl;
   starSquarePattern();
   cout<<endl<<"charSquarePattern"<<endl;
   charSquarePattern();
   cout<<endl<<"SquarePattern2"<<endl;
   SquarePattern2(n);
   cout<<endl<<"charSquarePattern2"<<endl;
   charSquarePattern2(n);
   cout<<endl<<"starTrianglePattern2"<<endl;
   starTrianglePattern2(n);
   cout<<endl<<"TrianglePattern2"<<endl;
   TrianglePattern2(4);
   cout<<endl<<"charTrianglePattern2"<<endl;
   charTrianglePattern2(4);
   cout<<endl<<"charTrianglePattern3"<<endl;
   charTrianglePattern3(4);
   cout<<endl<<"TrianglePattern3"<<endl;
   TrianglePattern3(4);
   cout<<endl<<"reversePattern3"<<endl;
   reversePattern3(4);
   cout<<endl<<"floydsTrianglePattern3"<<endl;
   floydsTrianglePattern3(4);
   cout<<endl<<"charfloydsTrianglePattern3"<<endl;
   charfloydsTrianglePattern3(4);
   cout<<endl<<"reverseCharfloydsTrianglePattern3"<<endl;
   reverseCharfloydsTrianglePattern3(4);
   cout<<endl<<"invertedTrianglePattern3"<<endl;
   invertedTrianglePattern3(4);
   cout<<endl<<"charInvertedTrianglePattern3"<<endl;
   charInvertedTrianglePattern3(4);
   cout<<endl<<"pyramidPattern"<<endl;
   pyramidPattern(4);
   cout<<endl<<"hollowPattern"<<endl;
   hollowPattern(4);
   cout<<endl<<"butterflyPattern"<<endl;
   butterflyPattern(4); // homework
   return 0;
}