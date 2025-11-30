#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->left = temp->right = nullptr;
    return temp;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    return 0;
}
