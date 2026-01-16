

#include <iostream>

using namespace std;

class Stack
{

    int size, top;
    int *arr;

public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = value;
            // cout << "Pushed value" << value << endl;
        }
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            // cout << arr[top] << endl;
            return arr[top];
        }
    }

    bool isEmpty()
    {
        if (top > 0)
            return false;
        else
            return true;
    }

    int currentStackSize()
    {
        cout << top + 1 << endl;

        return (top + 1);
    }

    void printStack()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Stack *s = new Stack(5);
    s->push(1);
    s->push(13);
    s->push(7);
    s->push(9);
    s->printStack();

    cout << endl;
    cout << s->peek();

    cout << endl;
    cout << s->isEmpty();

    cout << endl;
    s->pop();
    s->pop();
    s->printStack();

    cout << endl
         << s->currentStackSize();

    s->pop();
    s->pop();
    cout << endl;
    cout << s->isEmpty() << endl;
    cout << s->currentStackSize() << endl;

    s->pop();
    s->push(1);
    s->push(13);
    s->push(7);
    s->push(9);
    s->push(-10);
    s->printStack();
    cout << endl;
    s->push(19);
    cout << s->peek() << endl;
    return 0;
}