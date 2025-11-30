bool checkBST(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return checkBST(root->left, minVal, root->data) &&
           checkBST(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return checkBST(root, -1e9, 1e9);
}
