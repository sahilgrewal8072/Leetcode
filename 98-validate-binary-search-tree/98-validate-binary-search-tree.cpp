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
    bool solve(TreeNode* root, TreeNode* &pre){
        if(!root)return true;
        if(!solve(root->left, pre))return false;
        if(pre && pre->val >= root->val){
                return false;
        }
        pre = root;
        if(!solve(root->right, pre))return false;
        return true;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return solve(root, pre);
    }
};