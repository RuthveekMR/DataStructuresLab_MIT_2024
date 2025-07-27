#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert an element at the beginning of the list
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert an element at the end of the list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert an element before a given element
void insertBefore(Node*& head, int newData, int existingData) {
    if (head == nullptr) return;

    if (head->data == existingData) {
        insertAtBeginning(head, newData);
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != existingData) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Element " << existingData << " not found in the list." << endl;
        return;
    }

    Node* newNode = createNode(newData);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert an element after a given element
void insertAfter(Node*& head, int newData, int existingData) {
    Node* temp = head;
    while (temp != nullptr && temp->data != existingData) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Element " << existingData << " not found in the list." << endl;
        return;
    }

    Node* newNode = createNode(newData);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a given element from the list
void deleteElement(Node*& head, int data) {
    if (head == nullptr) return;

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Element " << data << " not found in the list." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Main function to drive the program
int main() {
    Node* head = nullptr;
    int choice, data, existingData;
    cout << "\nMenu:\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert before an element\n";
    cout << "4. Insert after an element\n";
    cout << "5. Delete an element\n";
    cout << "6. Print the list\n";
    cout << "7. Exit\n";
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert at beginning: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter the element to insert at end: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter the element to insert before: ";
                cin >> existingData;
                cout << "Enter the new element: ";
                cin >> data;
                insertBefore(head, data, existingData);
                break;
            case 4:
                cout << "Enter the element to insert after: ";
                cin >> existingData;
                cout << "Enter the new element: ";
                cin >> data;
                insertAfter(head, data, existingData);
                break;
            case 5:
                cout << "Enter the element to delete: ";
                cin >> data;
                deleteElement(head, data);
                break;
            case 6:
                printList(head);
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
        }
    } while (true);

    return 0;
}
