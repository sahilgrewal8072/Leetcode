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
    
    void convert_toString(TreeNode* root, string &ans){
       if(!root){
           return;
       }
        ans += to_string(root->val);
        if(!root->left && !root->right){
            return;
        }
        
            ans = ans + "(";
            convert_toString(root->left, ans);
            ans = ans + ")";
        
        
        if(root->right){
            ans = ans + "(";
            convert_toString(root->right, ans); 
            ans = ans + ")";
        }
        return;
    }
    
    string tree2str(TreeNode* root) {
          if(!root){return "";}
        string ans = "";
        // ans.append(to_string(root->val));
        convert_toString(root, ans);
        return ans;
    }
};