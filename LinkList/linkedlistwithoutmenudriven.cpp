#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete the first node of the list
    void deleteFromBeginning() {
        if (head == NULL) return;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    // Delete a node after a given node
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = NULL;
        if (temp != NULL && temp->data == key) { // Head node itself holds the key to be deleted
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return; // Key was not found
        prev->next = temp->next;
        delete temp;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    LinkedList list;
    
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(25);
    
    cout << "Current List: ";
    list.display();
    
    list.deleteFromBeginning();
    cout << "List After Deleting From Beginning: ";
    list.display();
    
    list.deleteNode(20);
    cout << "List After Deleting 20: ";
    list.display();

    return 0;
}
