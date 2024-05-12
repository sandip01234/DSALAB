//stack as ADT
#include <iostream>
using namespace std;

#define n 10

class Stack {
    int arr[n];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push() {
        int x;
        cout << "Enter the value to insert: " << endl;
        cin >> x;
        if (top == n - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }

    void checkFull() {
        if (top == n - 1) {
            cout << "Stack is full" << endl;
        } else {
            cout << "Stack is not full" << endl;
        }
    }

    void checkEmpty() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is not empty" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void makeEmpty() {
        top = -1;
    }

    void traversal() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack obj;
    int number;

    do {
        cout << "Enter a number to perform operations  below: " << endl;
        cout << "1) Insert" << endl;
        cout << "2) Delete" << endl;
        cout << "3) Check if stack is full" << endl;
        cout << "4) Check if stack is empty" << endl;
        cout << "5) Make stack empty" << endl;
        cout << "6) Traverse" << endl;
        cout << "7) Exit program" << endl;
        cin >> number;

        switch (number) {
            case 1:
                obj.push();
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                obj.checkFull();
                break;
            case 4:
                obj.checkEmpty();
                break;
            case 5:
                obj.makeEmpty();
                break;
            case 6:
                obj.traversal();
                break;
            case 7:
                cout << "Program is exiting..." << endl;
                break;
            default:
                cout << "Invalid input, insert again!!" << endl;
        }
    } while (number != 7);
    
    return 0;
}
