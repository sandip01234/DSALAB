#include <iostream>
#define MAX_LENGTH 10
using namespace std;

class PriorityQueue {
private:
    int count = 0;  // Number of elements in the queue
    int queue[MAX_LENGTH];

public:
    bool isFull() {
        return count == MAX_LENGTH;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        
        int i = count - 1;
        // Find the correct position for the item
        while (i >= 0 && queue[i] > item) {
            queue[i + 1] = queue[i];
            i--;
        }
        queue[i + 1] = item;
        count++;
        cout << item << " has been enqueued." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int dequeuedItem = queue[0];
        for (int i = 1; i < count; i++) {
            queue[i - 1] = queue[i];
        }
        count--;
        cout << dequeuedItem << " has been dequeued." << endl;
        return dequeuedItem;
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        for (int i = 0; i < count; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(3);
    pq.enqueue(7);
    pq.enqueue(1);
    pq.enqueue(5);
    pq.traverse();

    pq.dequeue();
    pq.traverse();

    pq.dequeue();
    pq.traverse();

    return 0;
}
