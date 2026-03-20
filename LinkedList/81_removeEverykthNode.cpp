
#include <iostream>
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
    // delete kth element from end
    ListNode *deleteNode(ListNode *head, int k)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        int fs = count - k;
        ListNode *curr = head, *prev = nullptr;
        if (fs == 0)
        {
            curr = head->next;
            delete head;
            head = curr;
            return head;
        }
        while (fs > 0)
        {
            prev = curr;
            curr = curr->next;
            fs--;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }

    // remove every kth node
    ListNode *removeKthNode(ListNode *head, int k)
    {
        /* ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        //cout << count << endl; */

        int count = 1;
        ListNode *curr = head;
        ListNode *prev = nullptr;

        if (k == 1)
            head = nullptr;
        while (curr)
        {
            if (count == k)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                count = 1;
            }
            else
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
        }
        return head;
    }

    // easy but lost , handle the edge cases properly,some cases fails
    //  rotate from last kth node
    ListNode *rotateKthNode(ListNode *head, int k)
    {
        ListNode *tail = head;
        ListNode *temp = head;
        int count = 1;
        while (tail->next)
        {
            tail = tail->next;
            count++;
        }
        cout << count << endl;
        int endNode = count - k;
        for (int i = 1; i < endNode; i++)
        {
            temp = temp->next;
        }

        tail->next = head;
        // temp = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
    }

    ListNode *reverseListNode(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = nullptr, *fut = nullptr;
        while (temp)
        {
            fut = temp->next;
            temp->next = prev;
            prev = temp;
            temp = fut;
        }
        head = prev;
        return head;
    }

    bool isListPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
            return true;
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        cout << count << endl;

        int fPart = count / 2;
        ListNode *prev = nullptr, *curr = head;
        while (fPart > 0)
        {
            prev = curr;
            curr = curr->next;
            fPart--;
        }

        prev->next = nullptr;

        // divided list in two parts
        // int sPart = count - fPart;
        ListNode *sHead = reverseListNode(curr);
        /*  ListNode *temp2 = sHead;
         while (temp2)
         {
             cout << temp2->value << " ";
             temp2 = temp2->next;
         } */

        while (head && sHead)
        {
            if (head->value != sHead->value)
                return false;
            head = head->next;
            sHead = sHead->next;
        }

        return true;
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

    // delete kth node
    /* ListNode *Head = s->deleteNode(head, 5);
    ListNode *temp2 = Head;
    while (temp2)
    {
        cout << temp2->value << " ";
        temp2 = temp2->next;
    } */

    // delete every kth node
    /* ListNode *Head = s->removeKthNode(head, 2);
    ListNode *temp2 = Head;
    while (temp2)
    {
        cout << temp2->value << " ";
        temp2 = temp2->next;
    } */

    // rotate from last kth node
    /* ListNode *Head = s->rotateKthNode(head, 5);
    ListNode *temp2 = Head;
    while (temp2)
    {
        cout << temp2->value << " ";
        temp2 = temp2->next;
    } */

    // check list is palindrome
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(2);
    head2->next->next->next->next->next = new ListNode(1);

    /* ListNode *head3 = s->reverseListNode(head);
    ListNode *temp2 = head3;
    while (temp2)
    {
        cout << temp2->value << " ";
        temp2 = temp2->next;
    } */
    cout << s->isListPalindrome(head2) << endl;

    return 0;
}
