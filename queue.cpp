
/*
 * Author: Mujtaba SP22-BSE-036
 * Date: April 5, 2023
 * Description: Queue implementation (Lab 6)
 */

#include <iostream>
#include <string>

using namespace std;

// Array implementation of queue
class IntQueue {
    private:
        int *queue;
        int size;
        int front;
        int rear;
        int count;
    public:
        IntQueue(int);
        ~IntQueue();
        void enqueue(int);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void display();
};

IntQueue::IntQueue(int s) {
    size = s;
    queue = new int[size];
    front = 0;
    rear = -1;
    count = 0;
}

IntQueue::~IntQueue() {
    delete [] queue;
}

void IntQueue::enqueue(int num) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        rear = (rear + 1) % size;
        queue[rear] = num;
        count++;
    }
}

int IntQueue::dequeue() {
    int num = 0;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        num = queue[front];
        front = (front + 1) % size;
        count--;
    }
    return num;
}

/* Shift-left based dequeue
int IntQueue::dequeue() {
    int num = 0;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        num = queue[front];
        for (int i = 0; i < count - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        count--;
    }
    return num;
}
 */

bool IntQueue::isFull() {
    bool status;
    if (count == size) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

bool IntQueue::isEmpty() {
    bool status;
    if (count == 0) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

void IntQueue::display() {
    for (int i = 0; i < count; i++) {
        cout << queue[(front + i) % size] << " ";
    }
    cout << endl;
}

// Double ended queue implementation
class Deque {
    private:
        int *queue;
        int size;
        int front;
        int rear;
        int count;
    public:
        Deque(int);
        ~Deque();
        void insertFront(int);
        void insertRear(int);
        int deleteFront();
        int deleteRear();
        bool isFull();
        bool isEmpty();
        void display();
};

Deque::Deque(int s) {
    size = s;
    queue = new int[size];
    front = 0;
    rear = -1;
    count = 0;
}

Deque::~Deque() {
    delete [] queue;
}

void Deque::insertFront(int num) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        queue[front] = num;
        count++;
    }
}

void Deque::insertRear(int num) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        rear = (rear + 1) % size;
        queue[rear] = num;
        count++;
    }
}

int Deque::deleteFront() {
    int num = 0;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        num = queue[front];
        front = (front + 1) % size;
        count--;
    }
    return num;
}

int Deque::deleteRear() {
    int num = 0;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        num = queue[rear];
        if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        count--;
    }
    return num;
}

bool Deque::isFull() {
    bool status;
    if (count == size) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

bool Deque::isEmpty() {
    bool status;
    if (count == 0) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

void Deque::display() {
    for (int i = 0; i < count; i++) {
        cout << queue[(front + i) % size] << " ";
    }
    cout << endl;
}

// Graded tasks

class LinkedQueue {
    private:
        struct QueueNode {
            int value;
            QueueNode *next;
        };
        QueueNode *front;
        QueueNode *rear;
        int count;
    public:
        LinkedQueue();
        ~LinkedQueue();
        void enqueue(int);
        int dequeue();
        bool isEmpty();
        void display();
};

LinkedQueue::LinkedQueue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
}

LinkedQueue::~LinkedQueue() {
    QueueNode *nodePtr = front;
    while (nodePtr != nullptr) {
        QueueNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

void LinkedQueue::enqueue(int num) {
    QueueNode *newNode = new QueueNode;
    newNode->value = num;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

int LinkedQueue::dequeue() {
    int num = 0;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        QueueNode *temp = front;
        num = temp->value;
        front = front->next;
        delete temp;
        count--;
    }
    return num;
}

bool LinkedQueue::isEmpty() {
    bool status;
    if (count == 0) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

void LinkedQueue::display() {
    QueueNode *nodePtr = front;
    while (nodePtr) {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

// Graded 2

class DoubleEndedLinkedQueue {
    private:
        struct QueueNode {
            int value;
            QueueNode *next;
            QueueNode *prev;
        };
        QueueNode *front;
        QueueNode *rear;
        int count;
    public:
        DoubleEndedLinkedQueue();
        ~DoubleEndedLinkedQueue();
        void insertFront(int);
        void insertRear(int);
        int deleteFront();
        int deleteRear();
        bool isEmpty();
        void display();
};

DoubleEndedLinkedQueue::DoubleEndedLinkedQueue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
}

DoubleEndedLinkedQueue::~DoubleEndedLinkedQueue() {
    QueueNode *nodePtr = front;
    while (nodePtr != nullptr) {
        QueueNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

void DoubleEndedLinkedQueue::insertFront(int num) {
    QueueNode *newNode = new QueueNode;
    newNode->value = num;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    count++;
}

void DoubleEndedLinkedQueue::insertRear(int num) {
    QueueNode *newNode = new QueueNode;
    newNode->value = num;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

int DoubleEndedLinkedQueue::deleteFront() {
    int num = 0;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        QueueNode *temp = front;
        num = temp->value;
        front = front->next;
        delete temp;
        count--;
    }
    return num;
}

int DoubleEndedLinkedQueue::deleteRear() {
    int num = 0;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        QueueNode *temp = rear;
        num = temp->value;
        rear = rear->prev;
        delete temp;
        count--;
    }
    return num;
}

bool DoubleEndedLinkedQueue::isEmpty() {
    bool status;
    if (count == 0) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

void DoubleEndedLinkedQueue::display() {
    QueueNode *nodePtr = front;
    while (nodePtr) {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}


int main() {
    IntQueue queue(5);
    int choice, num;
    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a number to enqueue: ";
                cin >> num;
                queue.enqueue(num);
                break;
            case 2:
                num = queue.dequeue();
                cout << "Dequeued number: " << num << endl;
                break;
            case 3:
                cout << "Queue: ";
                queue.display();
                break;
        }
    } while (choice != 4);

    LinkedQueue queue2;
    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a number to enqueue: ";
                cin >> num;
                queue2.enqueue(num);
                break;
            case 2:
                num = queue2.dequeue();
                cout << "Dequeued number: " << num << endl;
                break;
            case 3:
                cout << "Queue: ";
                queue2.display();
                break;
        }
    } while (choice != 4);

    Deque queue3 (10);
    do {
        cout << "1. Insert front" << endl;
        cout << "2. Insert rear" << endl;
        cout << "3. Delete front" << endl;
        cout << "4. Delete rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a number to insert: ";
                cin >> num;
                queue3.insertFront(num);
                break;
            case 2:
                cout << "Enter a number to insert: ";
                cin >> num;
                queue3.insertRear(num);
                break;
            case 3:
                num = queue3.deleteFront();
                cout << "Deleted number: " << num << endl;
                break;
            case 4:
                num = queue3.deleteRear();
                cout << "Deleted number: " << num << endl;
                break;
            case 5:
                cout << "Queue: ";
                queue3.display();
                break;
        }
    } while (choice != 6);

    DoubleEndedLinkedQueue queue4;
    do {
        cout << "1. Insert front" << endl;
        cout << "2. Insert rear" << endl;
        cout << "3. Delete front" << endl;
        cout << "4. Delete rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a number to insert: ";
                cin >> num;
                queue4.insertFront(num);
                break;
            case 2:
                cout << "Enter a number to insert: ";
                cin >> num;
                queue4.insertRear(num);
                break;
            case 3:
                num = queue4.deleteFront();
                cout << "Deleted number: " << num << endl;
                break;
            case 4:
                num = queue4.deleteRear();
                cout << "Deleted number: " << num << endl;
                break;
            case 5:
                cout << "Queue: ";
                queue4.display();
                break;
        }
    } while (choice != 6);

    return 0;
}

