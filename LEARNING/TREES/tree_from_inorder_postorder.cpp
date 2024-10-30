#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* post_in_order(int inorder[], int postorder[], int& postIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootValue = postorder[postIndex--];
    Node* root = new Node(rootValue);

    // Recursively build right and left subtrees
    root->right = post_in_order(inorder, postorder, postIndex, inorderMap[rootValue] + 1, inorderEnd, inorderMap);
    root->left = post_in_order(inorder, postorder, postIndex, inorderStart, inorderMap[rootValue] - 1, inorderMap);
    
    return root;
}

Node* buildTree(int inorder[], int postorder[], int n) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < n; ++i) {
        inorderMap[inorder[i]] = i;
    }

    int postIndex = n - 1;
    return post_in_order(inorder, postorder, postIndex, 0, n - 1, inorderMap);
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    
    Node* root = buildTree(inorder, postorder, n);
    
    cout << "Inorder traversal of constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
