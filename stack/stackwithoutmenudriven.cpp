#include <iostream>
using namespace std;

#define n 100

class Stack {
    int* arr;
    int top;

public:
    Stack() {
        arr = new int[n];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Stack is full." << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        top--;
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    void traversal() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack obj;
    obj.push(1);
    obj.push(3);
    obj.push(4);
    obj.traversal();

    cout << obj.Top() << endl;  // Should print 4

    obj.pop();
    cout << obj.Top() << endl;  // Should print 3
    obj.pop();
    cout << obj.Top() << endl;  // Should print 1
    obj.pop();
    cout << obj.Top() << endl;  // Should print "Stack is empty." and return -1
    cout << (obj.empty() ? "true" : "false") << endl;  // Should print true

    return 0;
}
