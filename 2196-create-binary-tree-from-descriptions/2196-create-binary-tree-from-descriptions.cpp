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
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> root_finder;
        
        for(auto &it : arr){
            TreeNode* parent = new TreeNode(it[0]);
            TreeNode* child = new TreeNode(it[1]);
            mp[it[0]] = parent;
            mp[it[1]] = child;
            root_finder[it[1]] = it[0];
        }
        
        TreeNode* root = nullptr;
        bool flag = false;
        
        for(auto &it : arr){
            if(root_finder.find(it[0]) == root_finder.end() && !flag){
                flag = true;
                root = mp[it[0]];
            }
            
            if(it[2] == 1){
                mp[it[0]]->left = mp[it[1]];
            }else{
                mp[it[0]]->right = mp[it[1]];
            }
        }
        return root;
    }
};