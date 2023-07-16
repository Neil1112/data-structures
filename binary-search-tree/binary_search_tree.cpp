#include <iostream>

// Structure representing a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node in the binary tree
Node* insertNode(Node* root, int value) {
    // If the tree is empty, create a new node and set it as the root
    if (root == nullptr) {
        return new Node(value);
    }

    // Otherwise, recur down the tree to find the appropriate position to insert the new node
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to print the binary tree in in-order traversal
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    // Create an empty binary tree
    Node* root = nullptr;

    // Insert nodes into the binary tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the binary tree using in-order traversal
    std::cout << "In-order traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}