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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp; // line level node
        queue<pair<TreeNode*, pair<int, int>>> q; // node - line - level
        q.push({root, {0, 0}});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int line = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            mp[line][level].insert(curr->val);
            if(curr->left){
                q.push({curr->left, {line - 1, level + 1}});
            }
            
            if(curr->right){
                q.push({curr->right, {line + 1, level + 1}});
            }
        }
        vector<vector<int>> final_ans;
        for(auto p : mp){
            vector<int> ans;
            for(auto q : p.second){
                ans.insert(ans.end(), q.second.begin(), q.second.end());
            }
            final_ans.push_back(ans);
        }
        return final_ans;
    }
};