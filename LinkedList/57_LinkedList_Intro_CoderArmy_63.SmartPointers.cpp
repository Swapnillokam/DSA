#include <iostream>
#include <memory>

using namespace std;

class ListNode
{
public:
    int val;
    unique_ptr<ListNode> next;
    ListNode(int value) : val(value), next(nullptr) {}
};

class List
{

public:
    unique_ptr<ListNode> head;

    void createLinkedList(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            unique_ptr<ListNode> newNode = make_unique<ListNode>(arr[i]);
            newNode->next = move(head);
            head = move(newNode);
        }
    }

    void insertAt(int pos, unique_ptr<ListNode> node)
    {
        ListNode *curr = head.get();
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next.get();
        }

        node->next = move(curr->next);
        curr->next = move(node);
    }

    void printList()
    {
        ListNode *curr = head.get();
        while (curr->next)
        {
            cout << curr->val << endl;
            curr = curr->next.get();
        }
        cout << curr->val << endl;
    }
};

int main()
{
    int arr[] = {2, 4, 6, 8};
    int size = 4;
    List *list = new List();
    list->createLinkedList(arr, size);
    // list->printList();
    // cout << Head->data << endl;
    list->insertAt(2, make_unique<ListNode>(5));
    list->printList();

    return 0;
}