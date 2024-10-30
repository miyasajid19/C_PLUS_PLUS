#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to build the tree
Node* pre_in_order(int inorder[], int preorder[], int& preIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootValue = preorder[preIndex++];
    Node* root = new Node(rootValue);
    
    // Recursively build left and right subtrees
    root->left = pre_in_order(inorder, preorder, preIndex, inorderStart, inorderMap[rootValue] - 1, inorderMap);
    root->right = pre_in_order(inorder, preorder, preIndex, inorderMap[rootValue] + 1, inorderEnd, inorderMap);
    
    return root;
}

// Function to build the tree using mappings
Node* buildTree(int inorder[], int preorder[], int n) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < n; ++i) {
        inorderMap[inorder[i]] = i;
    }

    int preIndex = 0;
    return pre_in_order(inorder, preorder, preIndex, 0, n - 1, inorderMap);
}

// Function to print inorder traversal
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    
    Node* root = buildTree(inorder, preorder, n);
    
    cout << "Inorder traversal of constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
