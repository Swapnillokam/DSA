#include <iostream>
using namespace std;

// leetcode Q - 567
// Not understood
// assume 0(1) -> assuming const since only 26 characters
bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int idx = s1[i] - 'a'; // a->0,b->1........
        freq[idx];
        idx++;
    }

    int WindSize = s1.length();

    // 0(n2)
    for (int i = 0; i < s2.length(); i++)
    {
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};
        while (windIdx < WindSize && idx < s2.length())
        {
            // int k = s2[idx] - 'a'; // a->0,b->1........
            // windFreq[k];
            // k++;
            // or

            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s1 = "ab", s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
    return 0;
}