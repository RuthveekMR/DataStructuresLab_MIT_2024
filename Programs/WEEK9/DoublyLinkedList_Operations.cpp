#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert at the rear end
    void insertAtRear(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) { // Empty list
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << data << " at the rear end.\n";
    }

    // Function to delete from the rear end
    void deleteFromRear() {
        if (tail == nullptr) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node* temp = tail;
        if (tail == head) { // Only one element in the list
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        cout << "Deleted " << temp->data << " from the rear end.\n";
        delete temp;
    }

    // Function to insert at a specific position
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 1) { // Insert at the head
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        } else {
            Node* temp = head;
            for (int i = 1; temp != nullptr && i < position - 1; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Position out of bounds.\n";
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            } else {
                tail = newNode;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << data << " at position " << position << ".\n";
    }

    // Function to delete from a specific position
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node* temp = head;
        if (position == 1) { // Delete the head
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; // If the list becomes empty
            }
        } else {
            for (int i = 1; temp != nullptr && i < position; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Position out of bounds.\n";
                return;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
            }
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
        }
        cout << "Deleted " << temp->data << " from position " << position << ".\n";
        delete temp;
    }

    // Function to insert after a specific element
    void insertAfterElement(int data, int element) {
        Node* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Element " << element << " not found in the list.\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }
        temp->next = newNode;
        cout << "Inserted " << data << " after element " << element << ".\n";
    }

    // Function to insert before a specific element
    void insertBeforeElement(int data, int element) {
        Node* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Element " << element << " not found in the list.\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->prev = temp->prev;
        newNode->next = temp;
        if (temp->prev != nullptr) {
            temp->prev->next = newNode;
        } else {
            head = newNode;
        }
        temp->prev = newNode;
        cout << "Inserted " << data << " before element " << element << ".\n";
    }

    // Function to print the list
    void printList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Menu-driven program
int main() {
    DoublyLinkedList dll;
    int choice, value, position, element;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at rear\n";
        cout << "2. Delete from rear\n";
        cout << "3. Insert at a given position\n";
        cout << "4. Delete from a given position\n";
        cout << "5. Insert after an element\n";
        cout << "6. Insert before an element\n";
        cout << "7. Print the list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at rear: ";
            cin >> value;
            dll.insertAtRear(value);
            break;
        case 2:
            dll.deleteFromRear();
            break;
        case 3:
            cout << "Enter value and position to insert: ";
            cin >> value >> position;
            dll.insertAtPosition(value, position);
            break;
        case 4:
            cout << "Enter position to delete: ";
            cin >> position;
            dll.deleteFromPosition(position);
            break;
        case 5:
            cout << "Enter value to insert and element after which to insert: ";
            cin >> value >> element;
            dll.insertAfterElement(value, element);
            break;
        case 6:
            cout << "Enter value to insert and element before which to insert: ";
            cin >> value >> element;
            dll.insertBeforeElement(value, element);
            break;
        case 7:
            dll.printList();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
