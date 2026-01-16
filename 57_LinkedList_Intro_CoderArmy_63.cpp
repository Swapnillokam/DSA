#include <iostream>
using namespace std;

// arrays  and vectors are contigeous in memory
// linked list are not contigeous in memory -> means cannnot be accessed by index like arrays and vectors i.r arr[2]
// linked lists are dynamic in nature like vectors

// HEAD -> points to the starting address of linked list

class Node
{
public:
    int value;
    Node *next;

    Node(int a)
    {
        value = a;
        next = NULL;
    }
};

class List
{
    Node *Head;
    Node *Tail;

public:
    List()
    {
        Head = Tail = NULL;
    }
    void push_front(int num)
    {
        if (Head == NULL)
        {
            Head = Tail = new Node(num);
        }
        else
        {
            Node *temp = new Node(num);
            temp->next = Head;
            Head = temp;
        }
    }

    void push_back(int num)
    {
        // Node *Tail = Head;
        // Tail = Head;
        // while (Tail->next != NULL)
        // {
        //     Tail = Tail->next;
        // }
        Node *newNode;
        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        {
            Node *newNode = new Node(num);
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    void pop_front()
    {
        if (!Head)
            return;

        Node *temp = Head;
        Head = temp->next;
        temp->next = NULL;
        delete temp;

        if (!Head) // list became empty
            Tail = nullptr;
    }

    void pop_back()
    {
        if (!Head)
            return;

        if (Head == Tail)
        {
            delete Head;
            Head = Tail = NULL;
            return;
        }

        Node *temp = Head;
        // while (temp->next->next == NULL) // or
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        temp->next = NULL;
        Tail = temp;
    }

    void insertAt(int value, int pos)
    {
        Node *temp = Head;
        Node *temp2 = new Node(3);
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        temp2->next = temp->next;
        temp->next = temp2;
    }

    void printAll()
    {
        Node *temp = Head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    List l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);

    l.printAll();

    cout << endl;
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.printAll();

    cout << endl;
    l.pop_front();
    l.printAll();

    cout << endl;
    l.pop_back();
    l.printAll();

    cout << endl;
    l.insertAt(3,2);
    l.printAll();

    return 0;
}