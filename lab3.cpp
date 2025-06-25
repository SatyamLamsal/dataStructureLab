#include <iostream>
#define MAX 5
using namespace std;

// Linear Queue
class LinearQueue {
    int arr[MAX];
    int front, rear;
public:
    LinearQueue() : front(-1), rear(-1) {}
    bool isFull() { return rear == MAX - 1; }
    bool isEmpty() { return front == -1 || front > rear; }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Linear Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << "Enqueued " << val << " to Linear Queue\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Linear Queue Underflow\n";
            return;
        }
        cout << "Dequeued " << arr[front++] << " from Linear Queue\n";
    }
    void display() {
        if (isEmpty()) {
            cout << "Linear Queue is empty\n";
            return;
        }
        cout << "Linear Queue: ";
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Circular Queue
class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() : front(-1), rear(-1) {}
    bool isFull() { return (front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front; }
    bool isEmpty() { return front == -1; }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Circular Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = val;
        cout << "Enqueued " << val << " to Circular Queue\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow\n";
            return;
        }
        cout << "Dequeued " << arr[front] << " from Circular Queue\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }
    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

// Deque (Double Ended Queue)
class Deque {
    int arr[MAX];
    int front, rear;
public:
    Deque() : front(-1), rear(-1) {}
    bool isFull() { return (front == 0 && rear == MAX - 1) || (front == rear + 1); }
    bool isEmpty() { return front == -1; }
    void addFront(int val) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        arr[front] = val;
        cout << "Added " << val << " at front of Deque\n";
    }
    void addRear(int val) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
        cout << "Added " << val << " at rear of Deque\n";
    }
    void delFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << "Deleted " << arr[front] << " from front of Deque\n";
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
    void delRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << "Deleted " << arr[rear] << " from rear of Deque\n";
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    LinearQueue lq;
    CircularQueue cq;
    Deque dq;

    
    lq.enqueue(1); lq.enqueue(2); lq.enqueue(3); lq.display();
    lq.dequeue(); lq.display();

    
    
    cq.enqueue(10); cq.enqueue(20); cq.enqueue(30); cq.enqueue(40); cq.enqueue(50);
    cq.display();
    cq.dequeue(); cq.dequeue(); cq.display();
    cq.enqueue(60); cq.display();

    
    dq.addFront(100); dq.addRear(200); dq.addFront(50); dq.display();
    dq.delFront(); dq.display();
    dq.delRear(); dq.display();

    return 0;
}
