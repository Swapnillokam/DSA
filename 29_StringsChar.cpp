#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

void Characters()
{
    /* code */
    // char str[] = {'a', 'b', 'c','\0'};
    // char str[] = "collage";
    // cout << str << endl;
    // cout << strlen(str) << endl;

    char str[100];
    cout << "Enter string" << endl;
    cin >> str;
    // problem with cin in character arrays
    //  if you give input "hello world" ,cin only takes hello(avoids after the voidspaces)
    // if you want to input the entire line along with void spaces you have to use cin.getline(string,size of string,delimiter?(optional))
    int len = 0;
    // cin.getline(str, 100);
    // cin.getline(str, 100, '.');  // not working
    // for (char ch : str)
    // {
    //     cout << ch << " ";
    //     len++;
    // }

    for (int i = 0; i < str[i] != '\0'; i++)
    {
        cout << str[i] << " ";
        len++;
    }
    cout << endl
         << len;
    // cout << str << endl;
}

void strings()
{
    // string s = "Swapnil Lokam";
    // cout << s << endl;

    // s = "DSA"; // dynamic -> runtime resize
    // cout << s << endl;

    // char c[] = "Swapnil lokam";
    // // c = "DSA";   //char are non modifiable unlike strings

    // string are modifiable but charracter arrays are not modifiable

    // string s1 = "Swapnil";
    // string s2 = " Lokam";

    // cout << s1.length() << endl;
    // cout << s2.length() << endl;
    // cout << s1 + s2;

    // to calculate length of string
    // for character arrays  - strlen(str)
    // for strings - str.length()

    string s;
    cout << "Enter the string" << endl;
    // cin >> s;
    getline(cin, s);

    // problem with cin in "strings"
    //  if you give input "hello world" ,cin only takes hello(avoids after the voidspaces)
    // if you want to input the entire line along with void spaces you have to use getline(cin, s,delimiter?(optional))

    // for character arrays   -> cin.getline(str, 100);

    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] == ' ')
    //     {
    //         cout << " ";
    //     }
    //     else
    //     {
    //         cout << s[i];
    //     }
    // }

    for (char ch : s)
    {
        cout << ch << " ";
    }

    // cout << s;
}

void reverseChar(vector<char> &c)
{
    int st = 0, end = c.size() - 1;
    while (st < end)
    {
        swap(c[st], c[end]);
        st++;
        end--;
    }
    for (char C : c)
    {
        cout << C << " ";
    }
}

void reverseString()
{
    string s = "Swapnil";
    // cout << *(s.begin()) << endl;
    // cout << *(s.end()-1) << endl;
    reverse(s.rbegin(), s.rend()); // iterators
    cout << s << endl;
    sort(s.begin(), s.end()); // iterators
    cout << s << endl;
}

bool checkStringPalindrome()
{
    // string s = "nayan";
    string s = "Swapnil";
    // cout << "Enter string to check the Palindrome" << endl;
    // cin >> s;
    int st = 0, end = s.length() - 1;
    while (st < end)
    {
        if (s[st] != s[end])
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}
int main()
{

    // Characters();
    // strings();
    // vector<char> c = {'S', 'W', 'A'};
    // reverseChar(c);
    reverseString();
    // cout << checkStringPalindrome();

    return 0;
}
