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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)return {};
        q.push(root);
        vector<vector<int>> ans;
        int count = 1;
        vector<int> tmp;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            tmp.push_back(curr->val);
            count--;
            if(count == 0){
                ans.push_back(tmp);
                count = q.size();
                tmp.clear();
            }
        
        }
        return ans; 
    }
};