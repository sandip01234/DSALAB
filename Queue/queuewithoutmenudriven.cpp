#include <iostream>
using namespace std;

#define MAX_LENGTH 10

class Queue {
private:
    int front = 0, rear = -1, queue[MAX_LENGTH];

public:
    bool isFull() {
        return rear == MAX_LENGTH - 1;
    }

    bool isEmpty() {
        return rear < front;
    }

    void makeEmpty() {
        rear = -1;
        front = 0;
        cout << "Queue is now empty." << endl;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Can't enqueue, queue is full." << endl;
            return;
        }
        queue[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Can't dequeue, queue is empty." << endl;
            return;
        }
        cout << "Dequeued: " << queue[front++] << endl;
        if (front > rear) {
            makeEmpty();
        }
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.traverse();

    q.dequeue();
    q.dequeue();
    q.traverse();

    q.dequeue();
    q.traverse();

    cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
    q.enqueue(20);
    q.traverse();
    return 0;
}
