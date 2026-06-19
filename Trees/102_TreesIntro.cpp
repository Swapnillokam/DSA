// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>

using namespace std;

class Node{
    
    public:
    int value;
    Node *left,*right;
    Node(int data)
    {
        value = data;
        left = NULL;
        right = NULL;
    }
};

int main() {
    
    queue<Node*> q;
    int x;
    cout<<"Enter value of root node ";
    cin>>x;
    Node *root = new Node(x);
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        cout<<"Enter Left node of "<<temp->value<<" : ";
        int first;
        cin>>first;
        if(first != -1)
        {
            temp->left = new Node(first);
            q.push(temp->left);
        }
        
        int second;
        cout<<"Enter right node of "<<temp->value<<" : ";
        cin>>second;
        if(second != -1)
        {
            temp->right = new Node(second);
            q.push(temp->right);
        }
        q.pop();
    }
    return 0;
}