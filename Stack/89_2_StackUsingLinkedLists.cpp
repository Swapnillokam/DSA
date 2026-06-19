//89_2_StackUsingLinkedLists
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val):data(val),next(nullptr){}
};

class Stack{
    int size;
    Node *top;
    public:
    Stack(){
        top = nullptr;
        size=0;
    }
    
    void push(int value)
    {
        Node *temp = new Node(value);
        if(!temp)
        {
            cout<<"Stack Undeoverrflow"<<endl;
            return;
        }
        temp->next = top;
        top = temp;
        size++;
        cout<<"Pushed "<<top->data<<" in stack"<<endl;
    }
    
    void pop()
    {
        if(!top) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        cout<<"Popped "<<temp->data<<" from stack"<<endl;
        delete temp;
        size--;
    }
    
    int peek()
    {
        if(!top)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }
    
    int Size()
    {
        return size;
    }
    
    bool isEmpty()
    {
        if(!top)
            return true;
        return false;
    }
    
};

int main() {
	Stack s;
	s.push(10);
	s.push(5);
	s.push(3);
	s.push(1);
	cout<<s.peek()<<endl;
	s.pop();
	cout<<s.Size()<<endl;
	cout<<s.isEmpty()<<endl;
	
	s.pop();
	s.pop();
	s.pop();
	cout<<s.Size()<<endl;
	cout<<s.isEmpty()<<endl;
	return 0;

}
