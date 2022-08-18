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
    private:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;
    
    void fill_parent(TreeNode* root){
        if(!root)return;
        if(root->left){
             parent[root->left] = root;
            fill_parent(root->left);
        }
        
        if(root->right){
            parent[root->right] = root;
            fill_parent(root->right);
        }
        return;
    }
    
    
    void dfs(TreeNode* target, int k){
        if(visited.find(target) != visited.end()){
            return;
        }
        
        visited.insert(target);
        if(k == 0){
            ans.push_back(target->val);
            return;
        }
        
        if(target->left){
            dfs(target->left, k-1);
        }
        
        if(target->right){
            dfs(target->right, k-1);
        }
        
        if(parent[target]){
            dfs(parent[target], k-1);
        }
        return;
    }
    
public:
    vector<int> ans;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            fill_parent(root);
            dfs(target, k);
        return ans;
            
    }
};