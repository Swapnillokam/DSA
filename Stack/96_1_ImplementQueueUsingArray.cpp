//96_1_ImplementQueueUsingArray
//https://www.geeksforgeeks.org/problems/implement-queue-using-array/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

/*
Implement a Queue using an Array, where the size of the array, n is given.
The Queue must support the following operations:

(i) enqueue(x): Insert an element x at the rear of the queue.
(ii) dequeue(): Remove the element from the front of the queue.
(iii) getFront(): Return front element if not empty, else -1.
(iv) getRear(): Return rear element if not empty, else -1.
(v) isEmpty(): Return true if the queue is empty else return false.
(vi) isFull(): Return true if the queue is full else return false.

There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2: Call dequeue()
3: Call getFront()
4: Call getRear()
5: Call isEmpty()
6: Call isFull()
You just have to implement the functions enqueue, dequeue, getFront, getRear, isEmpty and isFull and the driver code will handle the output.

Examples:

Input: n = 3, q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]
Output: [5, false, 4]
Explanation: Queries on queue are as follows:
enqueue(5): Insert 5 at the rear of the queue.
enqueue(3): Insert 3 at the rear of the queue.
enqueue(4): Insert 4 at the rear of the queue.
getFront(): Return the front element i.e 5.
dequeue(): Remove the front element 5 from the queue.
isEmpty(): Return false as the queue is not empty.
getRear(): Return the rear element i.e 4.
*/	

class myQueue {
    int *arr;
    int front,rear,size;
  public:
    myQueue(int n) {
        // Define Data Structures
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==-1;
    }

    bool isFull() {
        // check if the queue is full
        
        return rear>=size-1;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())
            return;
        if(isEmpty())
            front++;
        rear++;
        arr[rear]=x;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
            return;
        front++;
        if(front>rear)
        {
            front=-1;
            rear=-1;
        }
        if(front>0 && rear>0 && front == rear)
        {
            arr[0] = arr[front];
            front = 0;
            rear = 0;
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())
            return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty())
            return -1;
        return arr[rear];
    }
};


//using circular queue

class myQueue {
    int *arr;
    int front,rear,size;
  public:
    myQueue(int n) {
        // Define Data Structures
        size = n;
        arr = new int[size];
        front =-1;
        rear = -1;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==-1;
    }

    bool isFull() {
        // check if the queue is full
        return (rear+1)%size==front;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())
            return;
        if(isEmpty())
        {
            front=rear=0;
            arr[front]=x;
            return;
        }
        rear=(rear+1)%size;
        arr[rear]=x;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
            return;
        if(front==rear)
        {
            front=-1;
            rear=-1;
            return;
        }
        front=(front+1)%size;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())
            return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty())
            return -1;
        return arr[rear];
    }
};

//using linkedlist
class Node{
    public:
    int val;
    Node *next;
    Node(int x){
        val = x;
        next=nullptr;
    }
};

class myQueue {
    
  Node *front,*rear;
  public:
    myQueue(int n) {
        // Define Data Structures
        front = rear = nullptr;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==nullptr;
    }

    bool isFull() {
        // check if the queue is full
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        Node *ele = new Node(x);
        if(isEmpty())
            front = rear = ele;
        else 
        {
            rear->next=ele;
            rear = ele;
            
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
            return;
        Node *temp = front;
        front=front->next;
        delete temp;
        if(front==nullptr)
            rear=nullptr;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())
            return -1;
        return front->val;
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty())
            return -1;
        return rear->val;
    }
};