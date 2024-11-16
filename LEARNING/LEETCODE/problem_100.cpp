problem_100.cpp/**
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr and q == nullptr)
            return true;
        else if (p == nullptr and q != nullptr)
            return false;
        else if (p != nullptr and q == nullptr)
            return false;
        bool left = isSameTree(p->left, q->left);
        bool current = (p->val == q->val);
        bool right = isSameTree(p->right, q->right);
        return left and current and right;
    }
};