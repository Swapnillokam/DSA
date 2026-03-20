#include <iostream>

using namespace std;

// process
// 1. reverse both list
// 2. Addition operation
// 3. reverse the merged list

class NodeList
{
public:
    int val;
    NodeList *next;

    NodeList(int data) : val(data), next(nullptr) {}
};

NodeList *reverseList(NodeList *head)
{
    NodeList *curr = head, *prev = nullptr;
    NodeList *front = nullptr;

    while (curr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

int main()
{
    
    return 0;
}