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

// In-order traversal (recursive)
void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Post-order traversal (recursive)
void postOrderTraversal(Node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Pre-order traversal (recursive)
void preOrderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Count the number of leaf nodes in a binary tree
int countLeafNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1; // This is a leaf node
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = createBinaryTree();

    cout << "\nIn-order Traversal: ";
    inOrderTraversal(root);
    cout << "\nPost-order Traversal: ";
    postOrderTraversal(root);
    cout << "\nPre-order Traversal: ";
    preOrderTraversal(root);

    int leafCount = countLeafNodes(root);
    cout << "\nNumber of leaf nodes: " << leafCount << endl;

    return 0;
}
