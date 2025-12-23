#include <iostream>
using namespace std;

// leetcode Q 125
bool isAlphaNumeric(char c)
{
    if ((c >= '0' && c <= '9') || (tolower(c) >= 'a' && tolower(c) <= 'z'))
    {
        return true;
    }
    return false;
}

// 0(n)
bool checkPalindrome(string &s)
{
    int st = 0, end = s.length() - 1;
    while (st < end)
    {
        if (!isAlphaNumeric(s[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNumeric(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

// leetcode Q 1910
string removeAllPartOccurrencesInString(string &s, string part)
{
    // s.find(part) -> checks part exists in the string and returns the starting index of the part in the string
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    // string s = "Ac3?e3c&a";
    // string s = "race a car";
    // cout << checkPalindrome(s);
    
    // string s = "daabcbaabcbc", part = "abc";
    string s = "axxxxyyyyb", part = "xy";
    cout<<removeAllPartOccurrencesInString(s,part);
    return 0;
}
