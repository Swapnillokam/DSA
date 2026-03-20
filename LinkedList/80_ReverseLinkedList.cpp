
#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;

public:
    ListNode(int data) : value(data), next(nullptr) {}
};

class Solution
{

public:
    // first adding the list elements in the vector and then inserting the vector elements in the list in reversse order
    ListNode *reverseList(ListNode *head)
    {
        vector<int> ans;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            ans.push_back(temp->value);
            temp = temp->next;
        }
        temp = head;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            temp->value = ans[i];
            temp = temp->next;
        }
        return head;
    }

    // without vector creation , reversing the pointers of address of list
    ListNode *reverseList2(ListNode *head)
    {
        ListNode *prev = nullptr, *fut = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        head = prev;
        return head;
    }

    // middle of linked list
    // first traversing the entire list to get the count of the list
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        // cout << count << endl;
        temp = head;
        count = count / 2;
        while (count > 0)
        {
            temp = temp->next;
            count--;
        }
        return temp;
    }

    // no need to traveres the entire list to get the count
    ListNode *middleNode2(ListNode *head)
    {
        // slow and fast pointer concept
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution *s = new Solution();
    ListNode *temp = head;
    // original list
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    // reverse the list
    /* ListNode *Head = s->reverseList(head);
    ListNode *temp2 = Head;
    while(temp2){
        cout<<temp2->value<<" ";
        temp2 = temp2->next;
    } */

    /* ListNode *Head = s->reverseList2(head);
    ListNode *temp2 = Head;
    while(temp2){
        cout<<temp2->value<<" ";
        temp2 = temp2->next;
    } */

    // middle of list
    /* ListNode *middle = s->middleNode(head);
    cout << middle->value << endl; */

    ListNode *middle = s->middleNode2(head);
    cout << middle->value << endl;
    return 0;
}
#endif