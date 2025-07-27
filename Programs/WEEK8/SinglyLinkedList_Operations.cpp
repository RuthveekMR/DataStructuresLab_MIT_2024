#include <iostream>
using namespace std;

// Node structure
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

// Function to insert at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
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

// Function to insert before a given element
void insertBefore(Node*& head, int beforeData, int data) {
    if (head == nullptr) return;

    if (head->data == beforeData) {
        insertAtBeginning(head, data);
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != beforeData) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Element " << beforeData << " not found in the list." << endl;
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert after a given element
void insertAfter(Node*& head, int afterData, int data) {
    Node* temp = head;

    while (temp != nullptr && temp->data != afterData) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Element " << afterData << " not found in the list." << endl;
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node with given data
bool deleteNode(Node*& head, int data, int& dataOut) {
    if (head == nullptr) return false;

    Node* pLoc = head;
    Node* pPre = nullptr;

    // Search for the node to delete
    while (pLoc != nullptr && pLoc->data != data) {
        pPre = pLoc;
        pLoc = pLoc->next;
    }

    if (pLoc == nullptr) {
        cout << "Element " << data << " not found in the list." << endl;
        return false;
    }

    // Move pLoc data to dataOut
    dataOut = pLoc->data;

    // Deleting first node
    if (pPre == nullptr) {
        head = pLoc->next;
    } else {
        // Deleting other nodes
        pPre->next = pLoc->next;
    }

    delete pLoc; // Recycle the node
    return true;
}

// Function to print the list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main menu-driven program
int main() {
    Node* head = nullptr;
    int choice, data, dataOut, beforeData, afterData;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert before a given element\n";
        cout << "4. Insert after a given element\n";
        cout << "5. Delete an element\n";
        cout << "6. Print the list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter the element before which to insert: ";
                cin >> beforeData;
                cout << "Enter data to insert: ";
                cin >> data;
                insertBefore(head, beforeData, data);
                break;
            case 4:
                cout << "Enter the element after which to insert: ";
                cin >> afterData;
                cout << "Enter data to insert: ";
                cin >> data;
                insertAfter(head, afterData, data);
                break;
            case 5:
                cout << "Enter the element to delete: ";
                cin >> data;
                if (deleteNode(head, data, dataOut)) {
                    cout << "Deleted element: " << dataOut << endl;
                }
                break;
            case 6:
                printList(head);
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
