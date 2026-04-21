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

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << data << " inserted into queue" << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted element: " << front->data << endl;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
    }

    void peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element is: " << front->data << endl;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements:" << endl;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "\n--- QUEUE MENU ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            }
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}
