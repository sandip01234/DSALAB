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

    void enqueue() {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        
        int item;
        cout << "Enter a number to enqueue: ";
        cin >> item;
        
        int i;
        // Find the correct position for the item
        for (i = count - 1; (i >= 0 && queue[i] > item); i--) {
            queue[i + 1] = queue[i];
        }
        queue[i + 1] = item;
        count++;
        cout << item << " has been enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << queue[0] << " has been dequeued." << endl;
        for (int i = 1; i < count; i++) {
            queue[i - 1] = queue[i];
        }
        count--;
    }

    void makeEmpty() {
        count = 0;
        cout << "Queue is now empty." << endl;
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

    void mainProcess() {
        int operation;
        do {
            cout << "1) Enqueue\n2) Dequeue\n3) Make queue empty\n4) Traverse queue\n5) Exit\n";
            cout << "Enter your choice: ";
            cin >> operation;
            switch (operation) {
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    makeEmpty();
                    break;
                case 4:
                    traverse();
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid input, please try again." << endl;
            }
        } while (operation != 5);
    }
};

int main() {
    PriorityQueue pq;
    pq.mainProcess();
    return 0;
}
