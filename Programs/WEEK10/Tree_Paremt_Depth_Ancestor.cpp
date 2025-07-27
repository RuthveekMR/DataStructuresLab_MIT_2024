#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to create a binary tree
Node* createBinaryTree() {
    int val;
    cout << "Enter node value (-1 for no node): ";
    cin >> val;

    if (val == -1) {
        return nullptr; // No node
    }

    Node* newNode = new Node(val);
    cout << "Enter left child of " << val << ":\n";
    newNode->left = createBinaryTree();
    cout << "Enter right child of " << val << ":\n";
    newNode->right = createBinaryTree();

    return newNode;
}

// Function to find the parent of a given element
Node* findParent(Node* root, int childValue, Node* parent = nullptr) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data == childValue) {
        return parent; // Return the parent if found
    }
    Node* leftParent = findParent(root->left, childValue, root);
    if (leftParent) {
        return leftParent; // If found in left subtree
    }
    return findParent(root->right, childValue, root); // Search in right subtree
}

// Function to calculate the depth of the tree
int calculateDepth(Node* root) {
    if (root == nullptr) {
        return -1; // Depth of an empty tree is -1
    }
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);
    return max(leftDepth, rightDepth) + 1; // Return the maximum depth
}

// Function to print ancestors of a given node
bool printAncestors(Node* root, int target) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == target) {
        return true; // Target found
    }
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        cout << root->data << " "; // Print the ancestor
        return true;
    }
    return false; // Target not found in this path
}

int main() {
    Node* root = createBinaryTree();

    // Print parent of a given element
    int childValue;
    cout << "Enter the value of the node to find its parent: ";
    cin >> childValue;
    Node* parent = findParent(root, childValue);
    if (parent) {
        cout << "Parent of " << childValue << " is: " << parent->data << endl;
    } else {
        cout << "Parent not found or the node does not exist." << endl;
    }

    // Print depth of the tree
    int depth = calculateDepth(root);
    cout << "Depth of the tree: " << depth << endl;

    // Print ancestors of a given node
    int target;
    cout << "Enter the value of the node to find its ancestors: ";
    cin >> target;
    cout << "Ancestors of " << target << ": ";
    if (!printAncestors(root, target)) {
        cout << "Node not found." << endl;
    }
    cout << endl;

    return 0;
}
