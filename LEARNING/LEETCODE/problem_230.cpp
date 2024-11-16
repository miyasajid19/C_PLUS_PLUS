/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void inorder(TreeNode *temp, vector<int> &arr)
    {
        if (temp == nullptr)
        {
            return;
        }
        inorder(temp->left, arr);
        arr.push_back(temp->val);
        inorder(temp->right, arr);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr;
        inorder(root, arr);
        if (arr.size())
        {
            return arr[k - 1];
        }
        return INT_MAX;
    }
};