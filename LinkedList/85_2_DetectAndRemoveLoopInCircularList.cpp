#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data) : val(data), next(nullptr) {}
};

// own logic // didnt even try to understand logic from video
// hard problem
//  Time complexity - 0(n)
//  space complexity - 0(n)
ListNode *detectAndRemoveLoopFromLinkedList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = head;
    unordered_map<ListNode *, bool> m;

    // check loop exists
    while (curr)
    {
        if (m[curr] == 1)
            break;
        m[curr] = 1;
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    return head;
}

int lengthOfList(ListNode *head)
{
    ListNode *curr = head;
    int count = 1;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int checkYintersectionOfTwoLists(ListNode *head1, ListNode *head2)
{
    ListNode *curr1 = head1;
    ListNode *curr2 = head2;

    int diff;
    int curr1Length = lengthOfList(head1);
    int curr2Length = lengthOfList(head2);

    if (curr1Length > curr2Length)
    {
        diff = curr1Length - curr2Length;
        while (diff > 0)
        {
            // taking the longer list steps forward to match the starting point of the shorter list
            /* i.e.
                       head1
                         |
                 1 → 2 → 3 → 4
                               \
                                5 → 6 → 7
                               /
                         8 → 9
                         |
                       head2
                */
            curr1 = curr1->next;
            diff--;
        }
    }
    else
    {
        diff = curr2Length - curr1Length;
        while (diff > 0)
        { // taking the longer list steps forward to match the starting point of the shorter list
            curr2 = curr2->next;
            diff--;
        }
    }

    while (curr1 && curr2)
    {
        if (curr1 == curr2)
            return curr1->val;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

int main()
{
    // Create nodes
    /* ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    ListNode *n7 = new ListNode(7);
    ListNode *n8 = new ListNode(8);
    ListNode *n9 = new ListNode(9);
    ListNode *n10 = new ListNode(10);

    // Normal linking
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    // Create cycle: 10 -> 4
    n10->next = n4;
    // in video he used slow fast pointer
    // own method
    ListNode *curr = detectAndRemoveLoopFromLinkedList(n1);
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl; */

    /*
    head1
      |
     1 → 2 → 3 → 4
                   \
                    5 → 6 → 7
                   /
             8 → 9
              |
            head2
    */
    // Common part
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    ListNode *n7 = new ListNode(7);

    n5->next = n6;
    n6->next = n7;

    // First list
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode *head1 = n1;

    // Second list
    ListNode *n8 = new ListNode(8);
    ListNode *n9 = new ListNode(9);

    n8->next = n9;
    n9->next = n5;

    ListNode *head2 = n8;

    cout << "Linked lists created with intersection at node " << checkYintersectionOfTwoLists(head1, head2) << endl;
    return 0;
}