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
class Solution {
public:
void inorder(TreeNode* temp,set<int>&arr)
{
    if(temp==nullptr)
    {
        return;
    }
    inorder(temp->left,arr);
    arr.insert(temp->val);
    inorder(temp->right,arr);
}
    int findSecondMinimumValue(TreeNode* root) {

        set<int>arr;
        inorder(root,arr);
        if(arr.size()>1)
        {
            auto itr=arr.begin();
            advance(itr,1);
            return *itr;
        }
        return -1;
    }
};
