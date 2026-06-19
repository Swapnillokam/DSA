//adding two linked lists 

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode * next): val(x), next(next) {}
};

ListNode * reverseList(ListNode * head)
{
    ListNode * curr = head;
    ListNode * fut, * prev = nullptr;
    while (curr)
    {
        fut = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fut;
    }
    return prev;
}

int lastDigit(int val)
{
    return val % 10;
}

int carryForward(int val)
{
    val = val / 10;
    return val;
}

ListNode * addTwoLists(ListNode * head1, ListNode * head2)
{
    ListNode * curr1 = reverseList(head1);
    ListNode * curr2 = reverseList(head2);
    int carry = 0;
    ListNode * head = new ListNode(0);
    ListNode * curr = head;
    while (curr1 && curr2) {
        int sum = curr1 -> val + curr2 -> val + carry;
        curr -> next = new ListNode(lastDigit(sum));
        curr = curr->next;
        carry = carryForward(sum);
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    while (curr1)
    {
        int sum = curr1 -> val + carry;
        curr -> next = new ListNode(lastDigit(sum));
        curr = curr->next;
        carry = carryForward(sum);
        curr1 = curr1 -> next;
    }

    while (curr2)
    {
        int sum = curr2 -> val + carry;
        curr -> next = new ListNode(lastDigit(sum));
        curr = curr->next;
        carry = carryForward(sum);
        curr2 = curr2 -> next;
    }

    while (carry > 0)
    {
        curr -> next = new ListNode(lastDigit(carry));
        curr = curr->next;
        carry = carryForward(carry);
    }

    ListNode *res = head->next;
    delete head;
    return reverseList(res);
}

int main() {

    ListNode * head1 = new ListNode(9);
    head1 -> next = new ListNode(7);
    head1 -> next -> next = new ListNode(6);
    head1 -> next -> next -> next = new ListNode(8);
    head1 -> next -> next -> next -> next = new ListNode(4);

    ListNode * head2 = new ListNode(6);
    head2 -> next = new ListNode(4);
    head2 -> next -> next = new ListNode(3);
    head2 -> next -> next -> next = new ListNode(8);

    ListNode * curr = addTwoLists(head1, head2);

    while (curr)
    {
        std::cout << curr -> val << std::endl;
        curr = curr -> next;
    }

    return 0;
}