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
    private: 
    TreeNode* solve(TreeNode* root){
        if(!root)return nullptr;
        TreeNode* new_root = new TreeNode(root->val);
        new_root->right = solve(root->left);
        new_root->left = solve(root->right);
        return new_root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};