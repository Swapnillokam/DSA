#include <iostream>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    ListNode *Head;
    Head = NULL;
    int a[] = {1, 2, 3, 4, 5};

    // push_front
    for (int i = 0; i < 5; i++)
    {
        if (Head == NULL)
        {
            Head = new ListNode(a[i]);
        }
        else
        {
            ListNode *temp = new ListNode(a[i]);
            temp->next = Head;
            Head = temp;
        }
    }

    ListNode *temp = Head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
    // push_back
    ListNode *Tail = Head;
    while (Tail->next != NULL)
    {
        Tail = Tail->next;
    }
    ListNode *temp1 = new ListNode(6);
    Tail->next = temp1;
    Tail = temp1;

    int arr[] = {7, 8, 9};
    for (int i = 0; i < 3; i++)
    {
        ListNode *temp1 = new ListNode(arr[i]);
        Tail->next = temp1;
        Tail = temp1;
    }

    ListNode *temp2 = Head;
    while (temp2 != NULL)
    {
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }
}