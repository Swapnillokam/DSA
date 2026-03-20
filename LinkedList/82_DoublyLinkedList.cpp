#include <iostream>

using namespace std;

class ListNode
{
public:
    ListNode *prev, *next;
    int val;
    ListNode(int value) : val(value), prev(nullptr), next(nullptr) {}
};

class DLL
{
public:
    ListNode *head, *tail;
    DLL() { head = nullptr, tail = nullptr; }

    void push_front(int num)
    {
        // if list does not exist
        if (head == nullptr)
            head = new ListNode(num);
        // if alredy exist
        else
        {
            ListNode *temp = new ListNode(num);
            temp->next = head;
            head->prev = temp;
            tail = temp;
            head = temp;
        }
    }

    void push_back(int num)
    {
        // if list does not exist
        if (head == nullptr)
        {
            head = new ListNode(num);
            tail = head;
        }
        // if alredy exist
        else
        {
            ListNode *temp = new ListNode(num);
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    // inserting element at certain pos
    void insertAt(int num, int pos)
    {
        if (pos == 0)
        {
            // list does not exist
            if (head == nullptr)
                head = new ListNode(num);
            // if exist
            else
            {
                ListNode *temp = new ListNode(num);
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }
        else
        {
            ListNode *curr = head;
            ListNode *temp = new ListNode(num);
            while (pos - 1 > 0)
            {
                curr = curr->next;
                pos--;
            }
            // insert at end
            if (curr->next == nullptr)
            {
                curr->next = temp;
                temp->prev = curr;
                curr = temp;
            }
            // inser at middle
            else
            {
                temp->next = curr->next;
                temp->prev = curr;
                curr->next->prev = temp;
                curr->next = temp;
            }
        }
    }

    void deleteAt(int pos)
    {
        /* if (head == nullptr)
            return;
        // deleting at start
        //  if onlt one node exist
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        // if more than 1 node exist
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr;
        }

        // deleting at end
        //  if onlt one node exist
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        // if more than 1 node exist
        else
        {
            Node *temp = head, *curr = nullptr;
            while (temp->next)
            {
                curr = temp;
                temp = temp->next;
            }
            curr = temp->prev;
            curr->next = nullptr;
            delete temp;
        } */

        // from gpt -> lost in the above code

        if (head == nullptr)
            return;

        // deleting at start
        if (pos == 0)
        {
            // if only one node exist
            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            // if more than 1 node exist
            else
            {
                ListNode *temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
        }
        else
        {
            // delete at any position other than start

            ListNode *curr = head;
            int index = 0;

            // move to the required position
            while (curr != nullptr && index < pos)
            {
                curr = curr->next;
                index++;
            }

            // if position out of range
            if (curr == nullptr)
            {
                cout << "Position out of range\n";
                return;
            }

            // deleting at end
            // if last node
            if (curr->next == nullptr)
            {
                curr->prev->next = nullptr;
                delete curr;
            }
            // deleting at middle
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }
    }
};

int main()
{
    /* DLL *dll = new DLL();
    dll->push_front(5);
    dll->push_front(10);

    Node *temp = dll->head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    } */

    DLL *dll2 = new DLL();
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        dll2->push_back(arr[i]);
    }

    ListNode *temp = dll2->head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    dll2->insertAt(10, 5);
    ListNode *temp2 = dll2->head;
    while (temp2)
    {
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }
    cout << endl;
    dll2->deleteAt(2);
    ListNode *temp3 = dll2->head;
    while (temp3)
    {
        cout << temp3->val << " ";
        temp3 = temp3->next;
    }
    return 0;
}