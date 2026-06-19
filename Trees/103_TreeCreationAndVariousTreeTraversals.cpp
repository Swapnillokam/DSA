//103_TreeCreationAndVariousTreeTraversals
//do not forget to check the gfg questions below

#include <iostream>
using namespace std;


class Node{
    public:
    int val;
    Node *left,*right;
    
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};

//TC - O(n)
//for creating n nodes it takes n steps
//SC - O(n)
Node* BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
        return NULL;
    
    Node *temp = new Node(x);
    cout<<"Enter the Left child of "<<x<<" : ";
    temp->left = BinaryTree();
    cout<<"Enter the right child of "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
}

//N - node , l - left, r - right
//preorder -> n,l,r
//in order -> l,n,r
//post order ->l,r,n

//https://www.geeksforgeeks.org/problems/preorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
void preOrder(Node *root)
{
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//https://www.geeksforgeeks.org/problems/inorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
void inOrder(Node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

//https://www.geeksforgeeks.org/problems/postorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
void postOrder(Node *root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}


int main() {
    // Write C++ code here
    //Tree Creation
    cout<<"Enter the root node"<<endl;
    Node *root = BinaryTree();
    
    //preorder Print:
    cout<<"Pre Order : ";
    preOrder(root);
    
    //inorder Print:
    cout<<"in Order : ";
    inOrder(root);
    
    //postorder Print:
    cout<<"post Order : ";
    postOrder(root);

    return 0;
}


//output
//Enter the root node
//1
//Enter the Left child of 1 : 2
//Enter the Left child of 2 : 3
//Enter the Left child of 3 : 4
//Enter the Left child of 4 : -1
//Enter the right child of 4 : -1
//Enter the right child of 3 : 5
//Enter the Left child of 5 : -1
//Enter the right child of 5 : -1
//Enter the right child of 2 : 6
//Enter the Left child of 6 : -1
//Enter the right child of 6 : -1
//Enter the right child of 1 : 7
//Enter the Left child of 7 : -1
//Enter the right child of 7 : 8
//Enter the Left child of 8 : 9
//Enter the Left child of 9 : -1
//Enter the right child of 9 : -1
//Enter the right child of 8 : 10
//Enter the Left child of 10 : -1
//Enter the right child of 10 : -1
//
// TC and SC is 0(n) for each traversal
//Pre Order : 1 2 3 4 5 6 7 8 9 10 
//in Order : 4 3 5 2 6 1 7 9 8 10 
//post Order : 4 5 3 6 2 9 10 8 7 1 
//