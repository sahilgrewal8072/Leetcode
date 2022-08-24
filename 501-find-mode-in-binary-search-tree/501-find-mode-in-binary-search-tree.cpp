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
    void solve(TreeNode* root, int &mx_count, int &curr_count, int &prev, vector<int> &ans){
        if(!root)return;
        solve(root->left, mx_count, curr_count,  prev, ans);
        if(prev != -1 && prev == root->val){
            curr_count++;
        }else{
            curr_count = 1;
        }
        
        if(curr_count > mx_count){
            ans.clear();
            ans.push_back(root->val);
            mx_count = curr_count;
        }else if(curr_count == mx_count){
            ans.push_back(root->val);
        }
        prev = root->val;
        solve(root->right, mx_count, curr_count, prev, ans);
    }
    
public:
    
    vector<int> findMode(TreeNode* root) {
        int mx_count = -1;
        int prev = -1e7;
        vector<int> ans;
        int curr = 1;
        solve(root, mx_count, curr, prev, ans);
        return ans;
    }
};