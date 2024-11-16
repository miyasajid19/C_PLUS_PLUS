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

//approach 1
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
        inorder(root,ans);
        return ans;
        
    }
    void inorder(TreeNode* temp,vector<int>&arr)
    {
        if(temp==nullptr)
            return;
        inorder(temp->left,arr);
        arr.push_back(temp->val);
        inorder(temp->right,arr);
    }
};


//approach 2

class Solution {
public:
vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)
        return {};
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }