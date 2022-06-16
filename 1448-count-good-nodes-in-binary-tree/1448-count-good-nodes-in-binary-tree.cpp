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
    
    void solve(TreeNode* root, int mx_parent, int &count){
        if(!root)return;
        if(mx_parent <= root->val){
            count++;
            mx_parent = max(mx_parent, root->val);
        }
        
        solve(root->left, mx_parent, count);
        solve(root->right, mx_parent, count);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        int parent = INT_MIN;
        solve(root, parent, count);
        return count;         
    }
};