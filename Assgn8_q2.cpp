#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->left = n->right = nullptr;
    return n;
}

Node* insertNode(Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insertNode(root->left, val);
    else if (val > root->data) root->right = insertNode(root->right, val);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return nullptr;
}

int findMin(Node* root) {
    while (root->left) root = root->left;
    return root->data;
}

int findMax(Node* root) {
    while (root->right) root = root->right;
    return root->data;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* succ = nullptr;
    while (root) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* pred = nullptr;
    while (root) {
        if (key > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}
