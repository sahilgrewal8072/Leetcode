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
    
    vector<int> solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, int sum, vector<int> curr){
        
        if(!root){
            return curr;
        }
        sum += root->val;
        curr.push_back(root->val);
        solve(root->left, targetSum, ans, sum, curr);
        solve(root->right, targetSum, ans, sum, curr);
        if(!root->left && !root->right && sum == targetSum){
            ans.push_back(curr);
        }
        curr.pop_back();
        return curr;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root)return ans;
        vector<int> curr;
        solve(root, targetSum, ans, 0, curr);
        return ans;
    }
};