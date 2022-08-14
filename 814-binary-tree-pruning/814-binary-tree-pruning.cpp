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
    bool solve(TreeNode* root){
        if(!root)return false;
        
        int left1 = solve(root->left);
        int right1 = solve(root->right);
        
        if(!left1)root->left = nullptr;
        if(!right1)root->right = nullptr;
        return root->val == 1 || left1 || right1;
    }
       
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if(solve(root))return root;
        return nullptr;
    }
};