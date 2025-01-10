/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, int> visited;
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* p = q.front();
                q.pop();
                if(p->left){
                    parent[p->left] = p;
                    q.push(p->left);
                }
                
                if(p->right){
                    parent[p->right] = p;
                    q.push(p->right);
                }
            }
        }
        
       queue<pair<TreeNode*, int>> q2;
        q2.push({target, 0});
        visited[target]++;
        while(!q2.empty())
        {
            int size = q2.size();
            for(int i = 0; i< size; i++){
                TreeNode* p = q2.front().first;
                int dist = q2.front().second;
                q2.pop();
                if(dist == k){
                    ans.push_back(p->val);
                }
                if(dist > k)return ans;
                if(p->left && (visited.find(p->left) == visited.end())){
                    q2.push({p->left, dist + 1});
                    visited[p->left]++;
                }
                
                
                if(p->right && (visited.find(p->right) == visited.end())){
                    q2.push({p->right, dist + 1});
                    visited[p->right]++;
                }
                
                if(parent.find(p) != parent.end() && (visited.find(parent[p]) == visited.end())){
                    q2.push({parent[p], dist + 1});
                    visited[parent[p]]++;
                }
            }
        }
        return ans;
    }
};