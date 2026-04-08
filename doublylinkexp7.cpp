#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            this->prev = this->next = nullptr;
        }
};

class DoublyLinkedList {
    public:
        Node* head;

        DoublyLinkedList() {
            head = nullptr;
        }

        // INSERT at end
        void insert(int data) {
            Node* newNode = new Node(data);

            if (head == nullptr) {
                head = newNode;
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }

        // DELETE a value
        void deleteNode(int key) {
            Node* temp = head;

            while (temp != nullptr) {
                if (temp->data == key) {

                    // If head node
                    if (temp->prev == nullptr) {
                        head = temp->next;
                        if (head != nullptr)
                            head->prev = nullptr;
                    } else {
                        temp->prev->next = temp->next;
                        if (temp->next != nullptr)
                            temp->next->prev = temp->prev;
                    }
                    delete temp;
                    return;
                }
                temp = temp->next;
            }

            cout << "Value not found" << endl;
        }

        // DISPLAY list
        void display() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "null" << endl;
        }

        // ADD all elements
        int addition() {
            int sum = 0;
            Node* temp = head;

            while (temp != nullptr) {
                sum += temp->data;
                temp = temp->next;
            }
            return sum;
        }

        // SUBTRACTION (sequential)
        int subtraction() {
            if (head == nullptr) return 0;

            int result = head->data;
            Node* temp = head->next;

            while (temp != nullptr) {
                result -= temp->data;
                temp = temp->next;
            }
            return result;
        }

        // MULTIPLICATION
        int multiplication() {
            if (head == nullptr) return 0;

            int result = 1;
            Node* temp = head;

            while (temp != nullptr) {
                result *= temp->data;
                temp = temp->next;
            }
            return result;
        }

        // DIVISION (sequential)
        double division() {
            if (head == nullptr) return 0;

            double result = head->data;
            Node* temp = head->next;

            while (temp != nullptr) {
                if (temp->data == 0) {
                    cout << "Division by zero not allowed" << endl;
                    return 0;
                }
                result /= temp->data;
                temp = temp->next;
            }
            return result;
        }
};

// MAIN FUNCTION
int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(5);
    list.insert(2);

    cout << "Doubly Linked List:" << endl;
    list.display();

    cout << "Addition: " << list.addition() << endl;
    cout << "Subtraction: " << list.subtraction() << endl;
    cout << "Multiplication: " << list.multiplication() << endl;
    cout << "Division: " << list.division() << endl;

    list.deleteNode(5);
    cout << "After Deletion:" << endl;
    list.display();

    return 0;
}