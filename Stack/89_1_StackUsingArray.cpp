
//89_1_StackUsingArray
//note -> stack actual implementation is done using deque and not with array or linked lists
#include <bits/stdc++.h>

using namespace std;

class Stack {
    int size, * arr, top;
    public:
        Stack(int s) {
            size = s;
            top = -1;
            arr = new int[s];
        }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
        cout << "Pushed " << val << " in Stack" << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }

        cout << "Popped " << arr[top] << " from the Stack" << endl;
        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
    
    int Size()
    {
        return top+1;
    }
};

int main() {
    // your code goes here
    Stack s(5);
    cout<<s.Size()<<endl;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(10);
    s.push(11);
    cout<<s.Size()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.Size()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;
    cout<<s.Size()<<endl;
    
    return 0;

}