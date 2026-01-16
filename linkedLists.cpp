#include <iostream>
using namespace std;

class Node
{

public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    Node *Head;
    Head = NULL;
    int a[] = {1, 2, 3, 4, 5};

    // push_front
    for (int i = 0; i < 5; i++)
    {
        if (Head == NULL)
        {
            Head = new Node(a[i]);
        }
        else
        {
            Node *temp = new Node(a[i]);
            temp->next = Head;
            Head = temp;
        }
    }

    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
    // push_back
    Node *Tail = Head;
    while (Tail->next != NULL)
    {
        Tail = Tail->next;
    }
    Node *temp1 = new Node(6);
    Tail->next = temp1;
    Tail = temp1;

    int arr[] = {7, 8, 9};
    for (int i = 0; i < 3; i++)
    {
        Node *temp1 = new Node(arr[i]);
        Tail->next = temp1;
        Tail = temp1;
    }

    Node *temp2 = Head;
    while (temp2 != NULL)
    {
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }
}