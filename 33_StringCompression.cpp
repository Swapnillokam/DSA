#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compress(vector<char> &c)
{
    int idx = 0;
    for (int i = 0; i < c.size(); i++)
    {
        int count = 0;
        char ch = c[i];
        while (count < c.size() && c[i] == ch)
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            c[idx] = ch;
            idx++;
        }
        else if (count > 1)
        {
            c[idx] = ch;
            idx++;
            string s = to_string(count);
            for (char C : s)
            {
                c[idx] = C;
                idx++;
            }
        }
        i--;
    }
    c.resize(idx);
    return idx;
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}
// leetcode Q - 443
int main()
{
    vector<char> c = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << compress(c) << endl;
    return 0;
}