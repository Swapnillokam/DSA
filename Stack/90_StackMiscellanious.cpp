//lc-344 
//90_StackMiscellanious

//ReverseArray
/*
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/
void reverseString(vector<char>& s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }
        int i = 0;
        while (!st.empty()) {
            s[i] = st.top();
            st.pop();
            i++;
        }
    }

//https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1?page=2&category=Stack&difficulty=Easy&sortBy=submissions
//Insert an Element at the Bottom of a Stack
/*
Input:
n = 5
x = 2
st = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
*/

stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> helper;
        while(!st.empty())
        {
            helper.push(st.top());
            st.pop();
        }
        helper.push(x);
        while(!helper.empty())
        {
            st.push(helper.top());
            helper.pop();
        }
        return st;
    }

//https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1
//Make the array beautiful
/*
Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.
*/
vector<int> makeBeautiful(vector<int> arr) {
    stack<int> s;

    for (int i = 0; i < arr.size(); i++) {
        if (s.empty()) {
            s.push(arr[i]);
        }
        else if (arr[i] >= 0) {   // ✅ 0 treated as POSITIVE
            if (s.top() >= 0)
                s.push(arr[i]);
            else
                s.pop();
        }
        else { // arr[i] < 0
            if (s.top() < 0)
                s.push(arr[i]);
            else
                s.pop();
        }
    }

    vector<int> ans(s.size());
    int i = s.size() - 1;

    while (!s.empty()) {
        ans[i--] = s.top();
        s.pop();
    }

    return ans;
}


//https://www.geeksforgeeks.org/problems/string-manipulation3706/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions
//String Manipulation
/*
Input: arr[] = ["ab", "aa", "aa", "bcd", "ab"]
Output: 3
Explanation: After the first iteration, we'll have: ab bcd ab. We can't further destroy more strings and hence we stop and the result is 3. 
*/
int removeConsecutiveSame(vector<string>& arr) {
        // Your code goes here
        stack<string> s;
        for(int i=0;i<arr.size();i++)
        {
            if(s.empty())
                s.push(arr[i]);
            else if(s.top()==arr[i])
                s.pop();
            else
                s.push(arr[i]);  
        }
        return s.size();
    }

//lc - 921
//921. Minimum Add to Make Parentheses Valid
/*
Input: s = "())"
Output: 1

Input: s = "()))(("
Output: 4

*/
int minAddToMakeValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if(st.empty())
                st.push(s[i]);
            else if(st.top()=='(')
            {
                if(s[i]==')')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        return st.size();
    }

//lc - 20. Valid Parentheses

/*
Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false
*/

bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty())
                st.push(s[i]);
            else if (st.top() == '(') {
                if (s[i] == ')')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else if (st.top() == '[') {
                if (s[i] == ']')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else if (st.top() == '{') {
                if (s[i] == '}')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        if(st.empty())
            return true;
        return false;
    }

/*
lc - 844. Backspace String Compare
Solved
Easy
Topics
premium lock icon
Companies
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/

stack<char> filterString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!st.empty())
                    st.pop();
            } else
                st.push(s[i]);
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> s1 = filterString(s);
        stack<char> s2 = filterString(t);
        if (s1.size() != s2.size())
            return false;
        while (!s1.empty()) {
            if (s1.top() != s2.top()) {
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }

//https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions
/*
Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
*/
vector<int> bracketNumbers(string str) {
        int count=0;
        stack<int> s;
        vector<int> ans;
        for(int i = 0;i<str.length();i++)
        {
            if(str[i]=='(')
            {
                count++;
                s.push(count);
                ans.push_back(s.top());
            }
            else if(str[i]==')')
            {
                ans.push_back(s.top());
                s.pop();
            }
        }
        return ans;
    }


//https://www.geeksforgeeks.org/problems/get-min-at-pop/1?page=1&category=Stack&difficulty=Easy&sortBy=submissions
/*
//Get min at pop
You are given an integer array arr[]. You need to first push the elements of the array into a stack and then print minimum in the stack at each pop until stack becomes empty.

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: [1, 1, 1, 1, 1]
Explanation: 
After pushing elements to the stack, 
the stack will be "top -> 5, 4, 3, 2, 1". 
Now, start popping elements from the stack
popping 5: min in the stack is 1.popped 5
popping 4: min in the stack is 1. popped 4
popping 3: min in the stack is 1. popped 3
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
*/