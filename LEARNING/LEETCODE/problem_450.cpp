/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 class Solution {
public:
    TreeNode* findMax(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (key < root->val) {
            // Key is in the left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // Key is in the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Node with the key found
            if (root->left == nullptr && root->right == nullptr) {
                // Case 1: Leaf node
                delete root;
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {
                // Case 2: Only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else if (root->right != nullptr && root->left == nullptr) {
                // Case 2: Only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else {
                // Case 3: Two children
                TreeNode* maxNode = findMax(root->left); // Find max in the left subtree
                root->val = maxNode->val;               // Replace value
                root->left = deleteNode(root->left, maxNode->val); // Delete duplicate node
            }
        }
        return root;
    }
};
