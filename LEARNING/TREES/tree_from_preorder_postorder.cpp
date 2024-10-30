#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* post_pre_order(int preorder[], int postorder[], int& preIndex, int postStart, int postEnd, unordered_map<int, int>& postorderMap) {
    if (postStart > postEnd) {
        return nullptr;
    }

    int rootValue = preorder[preIndex++];
    Node* root = new Node(rootValue);

    if (postStart == postEnd) {
        return root;  // Leaf node
    }

    int index = postorderMap[preorder[preIndex]];

    // Recursively build left and right subtrees
    root->left = post_pre_order(preorder, postorder, preIndex, postStart, index, postorderMap);
    root->right = post_pre_order(preorder, postorder, preIndex, index + 1, postEnd - 1, postorderMap);
    
    return root;
}

Node* buildTree(int preorder[], int postorder[], int n) {
    unordered_map<int, int> postorderMap;
    for (int i = 0; i < n; ++i) {
        postorderMap[postorder[i]] = i;
    }

    int preIndex = 0;
    return post_pre_order(preorder, postorder, preIndex, 0, n - 1, postorderMap);
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    
    Node* root = buildTree(preorder, postorder, n);
    
    cout << "Inorder traversal of constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
