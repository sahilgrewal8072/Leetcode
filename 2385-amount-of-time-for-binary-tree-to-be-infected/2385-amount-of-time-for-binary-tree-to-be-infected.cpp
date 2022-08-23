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
    void to_graph(TreeNode* root, TreeNode* parent, unordered_map<int, vector<int>> &mp){
        if(!root){
            return;
        }
        
        if(parent != nullptr){
            mp[parent->val].push_back(root->val);
            mp[root->val].push_back(parent->val);
        }
        
        to_graph(root->left, root, mp);
        to_graph(root->right, root, mp);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
       unordered_map<int, vector<int>> mp;
        unordered_map<int, int> seen;
        to_graph(root,nullptr, mp);
        queue<int> q;
        int time = 0;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            time++;
            while(size--){
                int node = q.front();
                seen[node] = 1;
                q.pop();
                for(auto it : mp[node]){
                    if(!seen[it])
                    q.push(it);
                }
            }
        }
        return time-1;
    }
};