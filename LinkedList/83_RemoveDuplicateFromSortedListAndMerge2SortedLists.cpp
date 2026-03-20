#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int value) : val(value), next(nullptr) {};
};
// List is sorted
// given -> no.of nodes are 1 or more than one

// using extra space for vectors to store
ListNode *removeDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *curr = head;
    vector<int> v;
    v.push_back(curr->val);
    while (curr)
    {
        if (v[v.size() - 1] != curr->val)
            v.push_back(curr->val);
        curr = curr->next;
    }

    /* for (auto i : v)
    {
        cout << i << " ";
    } */

    curr = head;
    for (int i = 0; i < v.size(); i++)
    {
        curr->val = v[i];

        if (i == v.size() - 1)
            curr->next = nullptr;
        else
            curr = curr->next;
    }

    return head;
}

// without using extra space
//  using extra space for vectors to store
ListNode *removeDuplicates2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *prev = head;
    ListNode *curr = head->next;

    while (curr)
    {
        if (prev->val == curr->val)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

ListNode *mergeTwoSortedLists(ListNode *head1, ListNode *head2)
{
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    while (head1 && head2)
    {
        if (head1->val <= head2->val)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = nullptr;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    tail = head;
    head = head->next;
    delete tail;
    return head;
}

ListNode *sortLinkedList(ListNode *head)
{
    ListNode *curr = head;
    int count0 = 0, count1 = 0, count2 = 0;
    while (curr)
    {
        if (curr->val == 0)
            count0++;
        else if (curr->val == 1)
            count1++;
        else if (curr->val == 2)
            count2++;
        curr = curr->next;
    }

    curr = head;
    while (count0 > 0)
    {
        curr->val = 0;
        curr = curr->next;
        count0--;
    }
    while (count1 > 0)
    {
        curr->val = 1;
        curr = curr->next;
        count1--;
    }
    while (count2 > 0)
    {
        curr->val = 2;
        curr = curr->next;
        count2--;
    }

    return head;
}

int main()
{
    /* ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(5); */

    // Q LC - 83
    /* // ListNode *curr = removeDuplicates(head);
    ListNode *curr = removeDuplicates2(head);

    // Node *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl; */

    // Q LC - 21
    // Merge two Sorted lists
    /* ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(5);

    ListNode *head = mergeTwoSortedLists(head1, head2);

    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl; */

    // sort a list of 0s,1s,2s
    /* ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);

    ListNode *curr = sortLinkedList(head);
    while (curr)
    {   
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;  */



    return 0;
}