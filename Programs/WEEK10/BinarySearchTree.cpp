#include <iostream>
using namespace std;

// Define the structure for a binary search tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new value into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // Create a new node if the position is empty
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // Insert in the left subtree
    } else {
        root->right = insert(root->right, val); // Insert in the right subtree
    }
    return root;
}

// Function to search for a value in the BST
bool search(Node* root, int val) {
    if (root == nullptr) {
        return false; // Value not found
    }
    if (root->data == val) {
        return true; // Value found
    }
    if (val < root->data) {
        return search(root->left, val); // Search in the left subtree
    } else {
        return search(root->right, val); // Search in the right subtree
    }
}

// Function to delete the tree and free memory
void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    // Menu for inserting values and searching
    do {
        cout << "1. Insert value into BST\n";
        cout << "2. Search for a value in BST\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Value " << value << " inserted into BST.\n";
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Value " << value << " found in BST.\n";
                } else {
                    cout << "Value " << value << " not found in BST.\n";
                }
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    // Clean up memory
    deleteTree(root);
    return 0;
}
