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
    void solve(TreeNode* root, int &ans, int curr){
        if(!root){
            return;
        }
        
        curr *= 10;
        curr += root->val;
        solve(root->left, ans, curr);
        solve(root->right, ans, curr);
        if(root && !root->left && !root->right){
            ans += curr;
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }
};