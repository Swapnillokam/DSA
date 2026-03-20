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

bool isVisited(vector<ListNode *> &visited, ListNode *curr)
{
    for (auto i : visited)
    {
        if (i == curr)
            return true;
    }
    return false;
}

// Time complexity - 0(n2)
bool detectLoopInLinkedList(ListNode *head)
{
    ListNode *curr = head;
    vector<ListNode *> visited;

    while (curr)
    {
        if (isVisited(visited, curr))
        {
            return true;
        }
        visited.push_back(curr);
        curr = curr->next;
    }

    return false;
}

// Time complexity - 0(n)
// space complexity - 0(n)
bool detectLoopInLinkedList2(ListNode *head)
{
    ListNode *curr = head;
    unordered_map<ListNode *, bool> visited;

    while (curr)
    {
        if (visited[curr] == 1)
        {
            return true;
        }
        visited[curr] = 1;
        curr = curr->next;
    }

    return false;
}

// Time complexity - 0(n)
// space complexity - 0(1)
// slow and fast pointer approach
bool detectLoopInLinkedList3(ListNode *head)
{
    ListNode *curr = head;
    ListNode *slow = curr;
    ListNode *fast = curr;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int detectCircularLoopLength(ListNode *head)
{
    // slow and fast pointer appraoch
    ListNode *slow = head;
    ListNode *fast = head;

    //checking if there is a circular loop
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    //checking if htere is only one node
    if (fast == nullptr || fast->next == nullptr)
        return 0;

    //counting the nodes
    int count = 1;
    slow = slow->next;
    while (slow != fast)
    {
        slow = slow->next;
        count++;
    }
    return count;
}

int main()
{
    // Create nodes
    ListNode *n1 = new ListNode(1);
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

    ListNode *head = n1;

    // 0(n2)
    // cout << "is there a loop on this linked list : " << detectLoopInLinkedList(head) << endl;
    // cout << "is there a loop on this linked list : " << detectLoopInLinkedList2(head) << endl;

    // slow and fast pointer appraoch
    // cout << "is there a loop on this linked list : " << detectLoopInLinkedList3(head) << endl;

    // detect length of the circular loop
    cout << "the length of the circular linked list : " << detectCircularLoopLength(head) << endl;
    return 0;
}