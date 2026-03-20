//

#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int value)
    {
        value = value;
        next = nullptr;
    }
};

// confusing creating linked list with recursion check again
ListNode *recLinkedList(int arr[], int size, int index)
{
    if (index == size)
    {
        return nullptr;
    }

    ListNode *temp = new ListNode(arr[index]);
    temp->next = recLinkedList(arr, size, index + 1);
    return temp;
}
int main()
{
    ListNode *Head;
    Head = nullptr;

    int arr[] = {2, 4, 6, 8};
    for (int i : arr)
    {
        if (Head == nullptr)
        {
            Head = new ListNode(i);
        }
        else
        {
            ListNode *temp = new ListNode(i);
            temp->next = Head;
            Head = temp;
        }
    }

    // Node *temp = Head;
    // adding elements before nodes
    // while (temp)
    // {
    //     cout << temp->data << endl;
    //     temp = temp->next;
    // }

    // inserting node in between
    /* Node *temp2 = new Node(30);
    Node *Head2 = Head;
    Node *moveTemp = Head2;
    int insertAt = 2;

    for (int i = 1; i < insertAt; i++)
    {
        moveTemp = Head2->next;
        Head2 = moveTemp;
    }

    // cout<<Head->data;
    temp2->next = moveTemp->next; // understand through pen and paper
    moveTemp->next = temp2;

    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    cout << Head->data; */

    // deleting Head node
    /* if (Head)
    {
        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }
    // cout << Head->data;

    Node *temp2 = Head;
    while (temp2)
    {
        cout << temp2->data << endl;
        temp2 = temp2->next;
    } */

    // deleting lastnode
    /* if (Head != nullptr)
    {
        if (Head->next == nullptr)
        {
            Node *temp = Head;
            delete temp;
            Head = nullptr;
        }
        else
        {
            Node *curr = Head;
            Node *prev = Head;
            while (curr->next)
            {
                prev = curr;
                curr = curr->next;
            }
            // cout << Tail->data;
            // cout << Head->data;

            // cout << curr->data << endl;
            // cout << prev->data << endl;

            prev->next = nullptr;
            delete curr;
        }
    }

    Node *temp = Head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    } */

    // deleting particular node
    int deletaAt = 3;
    ListNode *curr = Head;
    ListNode *prev = Head;

    //check the video to understand the edge case when 1st node has to be deleted
    for (int i = 1; i < deletaAt; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    ListNode *temp = Head;
    while (temp)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }

    //check the recursive deletion later on the video

    // adding elements after nodes
    //  keeping track of head and tail
    /* int arr[] = {2, 4, 6, 8};
    Node *Tail = nullptr;
    for (int i : arr)
    {
        if (Head == nullptr)
        {
            Head = new Node(i);
            Tail = Head;
        }
        else
        {
            // Node *temp = new Node(i);
            // temp->next = Head;
            // Head = temp;

            Tail->next = new Node(i);
            Tail = Tail->next;
        }
    }
    Node *temp = Head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    } */

    // recLinkedList
    /* int arr[] = {1, 2, 3};
    Node *List = recLinkedList(arr, 3, 0);
    Node *temp = List;
    while (temp->next)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
 */
    return 0;
}