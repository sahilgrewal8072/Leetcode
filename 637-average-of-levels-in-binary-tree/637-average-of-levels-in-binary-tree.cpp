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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root && !root->left && !root->right){
            ans.push_back(root->val);
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            double size = q.size();
            double x = size;
            double curr = 0;
            while(x--){
                auto it = q.front();
                q.pop();
                curr += it->val;
                if(it->left){
                    q.push(it->left);
                }
                
                if(it->right){
                    q.push(it->right);
                }
            }
            
            ans.push_back(curr/size);
        }
        return ans;
    }
};