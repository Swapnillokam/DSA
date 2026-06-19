//104_BinaryTreeProblems
//note for level order traversal you can use queue but for pre,post,in order traversal you can use recursion

#include<iostream>
#include<vector>
#include<queue>

// 1. Level Order Traversal
using namespace std;
//A binary tree Node
/* class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */


//https://www.geeksforgeeks.org/problems/level-order-traversal/1?page=1&difficulty[]=0&category[]=Tree&sortBy=submissions
class Solution {
  public:
	//TC - O(n)  ,// SC - O(n) --> for queue
    void levelOrderTraversal(Node *root,vector<int> &ans,queue<Node*> &q)
    {
        Node *temp;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    
    vector<int> levelOrder(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        q.push(root);
        levelOrderTraversal(root,ans,q);
        return ans;
    }
};

//2. Size of binary tree
//https://www.geeksforgeeks.org/problems/size-of-binary-tree/1?page=1&difficulty[]=-1&category[]=Tree&sortBy=submissions
class Solution {
  public:
    //NOte - sending the count argument as a reference otherwise it gives wron answer
    void BinaryTree(Node *root,int &count)
    {
        if(root == nullptr)
            {  // count--;
                return;}
        count++;
        // cout<<count<<" ";
        BinaryTree(root->left,count);
        BinaryTree(root->right,count);
        // return count;
    }
    //TC - O(n), SC - O(n)
    //another way
    int BT(Node *root)
    {
        if(root == nullptr)
            return 0;
        return 1 + BT(root->left) + BT(root->right);
    }
    int getSize(Node* root) {
        // code here
        int count = 0;
        // BinaryTree(root,count);
        // return count;
        return BT(root);
    }
};

//3. sum of binary tree
//https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
class Solution {
  public:
  
    void BT(Node* root,int &sum)
    {
        if(root == nullptr)
            return;
        sum += root->data;
        // cout<<sum<<" ";
        BT(root->left,sum);
        BT(root->right,sum);
    }

    //another way
    int BT2(Node* root)
    {
        if(root == nullptr)
            return 0;
        return root->data + BT2(root->left) + BT2(root->right);
    }

    int sumBT(Node* root) {
        // code here
        // int sum = 0;
        // BT(root,sum);
        // return sum;

        return BT2(root);
    }
};


//count no.of leaf nodes 
//https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    
    void leafNode(Node *root,int &count)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr && root->right==nullptr)
        {
            count++;
            return;
        }
        leafNode(root->left,count);
        leafNode(root->right,count);
    }
    
    //another way
    int leafNode2(Node *root)
    {
        if(root==nullptr)
            return 0;
        if(root->left==nullptr && root->right==nullptr)
        {
            return 1;
        }
        return leafNode2(root->left) + leafNode2(root->right);
    }
    
    
    int countLeaves(Node* root) {
        // write code here
        // int count = 0;
        // leafNode(root,count);
        // return count;
        
        return leafNode2(root);
    }
};


//count non leaf nodes 
//https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
  public:
  
    void nonLeafNodes(Node *root,int &count)
    {
        if(root == nullptr)
            return;
        if(root->left || root->right)
        {
            count++;
        }
        nonLeafNodes(root->left,count);
        nonLeafNodes(root->right,count);
    }
    
    //another way 
    int nonLeafNodes2(Node* root)
    {   if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
          return 0;
        return 1+nonLeafNodes2(root->left) + nonLeafNodes2(root->right);
    }
    int countNonLeafNodes(Node* root) {
        // Code here
        // int count = 0;
        // nonLeafNodes(root,count);
        // return count;
        
        return nonLeafNodes2(root);
    }
};
//Try to understand the concept
/*
If you want to use a count argument, then make it an accumulator that's passed by reference.

class Solution {
  public:
    void nonLeafNodes(Node* root, int &count)
    {
        if(root == nullptr)
            return;

        if(root->left != nullptr || root->right != nullptr)
            count++;

        nonLeafNodes(root->left, count);
        nonLeafNodes(root->right, count);
    }

    int countNonLeafNodes(Node* root) {
        int count = 0;
        nonLeafNodes(root, count);
        return count;
    }
};
Why your version doesn't work

You wrote:

return nonLeafNodes(root->left, count+1)
     + nonLeafNodes(root->right, count+1);

Here count+1 is passed by value, so each recursive call gets its own copy. The incremented value is never accumulated into a shared count.

If you insist on keeping count as a parameter and returning an int, you could do:

int nonLeafNodes(Node* root, int count)
{
    if(root == nullptr)
        return count;

    if(root->left != nullptr || root->right != nullptr)
        count++;

    count = nonLeafNodes(root->left, count);
    count = nonLeafNodes(root->right, count);

    return count;
}

and call it as:

return nonLeafNodes(root, 0);

But the reference version is the cleaner way to use a count argument.
*/

// maximum height of the tree 
//https://www.geeksforgeeks.org/problems/height-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions
/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    void findMaxHeight(Node *root,int count,int &maxHeight)
    {
        if(root == nullptr)
            return;
        maxHeight = max(count,maxHeight);
        findMaxHeight(root->left,count+1,maxHeight);
        findMaxHeight(root->right,count+1,maxHeight);
    }
  
    //another way
    int maxCountLenght(Node *root)
    {
        if(root == nullptr)
            return 0;
        return 1 + max(maxCountLenght(root->left),maxCountLenght(root->right));
    }
    
    int height(Node* root) {
        // // code here
        // int maxHeight = 0;
        // findMaxHeight(root,0,maxHeight);
        // return maxHeight;
        return maxCountLenght(root) - 1; //note -1
    }
};


//largest value in each level
//https://www.geeksforgeeks.org/problems/largest-value-in-each-level/1?page=4&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions
// User function Template for C++

class Solution {
	public:
	vector<int> largestValues(Node* root) {
		// code here
		vector<int> ans;
		if (root == nullptr)
			return ans;
		
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
			{
			int maxi = INT_MIN;
			int size = q.size();
			for (int i = 0; i<size; i++)
				{
				Node* temp = q.front();
				q.pop();
				
				maxi = max(maxi, temp->data);
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
			ans.push_back(maxi);
		}
		return ans;
	}
};
