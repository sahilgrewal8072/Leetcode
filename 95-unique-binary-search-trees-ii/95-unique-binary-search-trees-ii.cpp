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
    // vector<TreeNode*> ans;
    vector<TreeNode*> solve(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(nullptr);
            return result;
        }
        
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = solve(start, i-1);
            vector<TreeNode*> right = solve(i+1, end);
            for(auto it : left){
                for(auto pt : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = it;
                    root->right = pt;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)return {};
        return solve(1, n);
    }
};