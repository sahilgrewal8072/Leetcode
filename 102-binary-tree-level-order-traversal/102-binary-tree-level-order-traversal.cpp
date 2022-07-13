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
        vector<vector<int>> ans;
        if(!root)return ans;
        q.push(root);
         vector<int> temp;
        int count = 1;
        while(!q.empty()){
            auto it = q.front();
            if(it->left)q.push(it->left);
            if(it->right)q.push(it->right);
            temp.push_back(it->val);
            q.pop();
            if(--count == 0){
                ans.push_back(temp);
                temp.clear();
                count = q.size();
            }
            
        }
        return ans;
    }
};