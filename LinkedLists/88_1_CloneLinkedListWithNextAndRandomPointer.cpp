//gfg -> https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
//88_1_CloneLinkedListWithNextAndRandomPointer
//brute force approach 0(n2)
//optimized approach ->0(n)-> check video


#include <bits/stdc++.h>

using namespace std;

class Node {
    public: int data;
    Node * next;
    Node * random;

    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

/* -------- CLONE FUNCTION (O(N), O(1)) -------- */
Node * cloneLinkedList(Node * head) {
    if (!head) return NULL;

    Node * curr = head;

    // STEP 1: Insert cloned nodes
    while (curr) {
        Node * newNode = new Node(curr -> data);
        newNode -> next = curr -> next;
        curr -> next = newNode;
        curr = newNode -> next;
    }

    // STEP 2: Copy random pointers
    curr = head;
    while (curr) {
        if (curr -> random)
            curr -> next -> random = curr -> random -> next;
        curr = curr -> next -> next;
    }

    // STEP 3: Separate original and clone
    curr = head;
    Node * cloneHead = head -> next;
    Node * cloneCurr = cloneHead;

    while (curr) {
        curr -> next = curr -> next -> next;
        if (cloneCurr -> next)
            cloneCurr -> next = cloneCurr -> next -> next;

        curr = curr -> next;
        cloneCurr = cloneCurr -> next;
    }

    return cloneHead;
}

/* -------- PRINT FUNCTION -------- */
void printList(Node * head) {
    Node * curr = head;
    int index = 1;
    unordered_map < Node * , int > indexMap;

    // Assign indices
    curr = head;
    while (curr) {
        indexMap[curr] = index++;
        curr = curr -> next;
    }

    // Print nodes
    curr = head;
    while (curr) {
        cout << "[ " << curr -> data << ", ";
        if (curr -> random)
            cout << indexMap[curr -> random];
        else
            cout << "NULL";
        cout << " ]  ";
        curr = curr -> next;
    }
    cout << endl;
}

/* -------- MAIN (TESTING) -------- */
int main() {

    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    Node * head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);

    Node * n1 = head;
    Node * n2 = head -> next;
    Node * n3 = head -> next -> next;
    Node * n4 = head -> next -> next -> next;
    Node * n5 = head -> next -> next -> next -> next;

    // Setting random pointers
    n1 -> random = n3; // [1,3]
    n2 -> random = n1; // [2,1]
    n3 -> random = n5; // [3,5]
    n4 -> random = n3; // [4,3]
    n5 -> random = n2; // [5,2]

    cout << "Original List:\n";
    printList(head);

    Node * clonedHead = cloneLinkedList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    cout << "\nOriginal List After Cloning (Should be unchanged):\n";
    printList(head);

    return 0;
}
