#include <iostream>

using namespace std;

class Queue
{
    int *a;
    int size;
    int front, rear;

public:
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        a = new int[size];
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
            a[0] = value;
        }
        else
        {
            rear++;
            a[rear] = value;
        }
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    int currentQueueSize()
    {
        if (isEmpty())
            return 0;

        return rear - front + 1;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "queue underflow" << endl;
            return;
        }

        if (front == rear)
            front = rear = -1; // saving the time complexity
        else
            front++;
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return a[front];
    }

    int last()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return a[rear];
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return;
        }
        else
        {
            for (int i = front; i <= rear; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }

    ~Queue()
    {
        delete[] a;
    }
};

int main()
{
    Queue *q = new Queue(5);
    // q->size();
    // cout << endl;

    q->push(10);
    q->push(20);
    q->push(50);
    q->push(30);
    q->push(100);
    q->push(70);
    q->printQueue();
    cout << q->isFull() << endl;

    q->pop();
    q->printQueue();

    cout << q->start() << endl;
    cout << q->last() << endl;
    
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    
    cout << q->isEmpty() << endl;

    return 0;
}