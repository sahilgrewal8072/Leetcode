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
    void solve(TreeNode* root, int mask, int &ans){
        if(!root)return;
        
        mask ^= (1 << root->val);
        if(!root->left && !root->right && (mask & (mask - 1)) == 0){
            ans++;
            return;
        }
        solve(root->left, mask, ans);
        solve(root->right, mask, ans);
        
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};