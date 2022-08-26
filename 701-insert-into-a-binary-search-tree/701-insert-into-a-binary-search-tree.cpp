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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if(!root){
            return temp;
        }
        
        TreeNode* prev = nullptr;
        
        TreeNode* curr = root;
        
        while(curr){
            prev = curr;
            if(curr->val < val){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        
        if(!curr){
            if(val > prev->val){
                prev->right = temp;
            }else{
                prev->left = temp;
            }
        }
        return root;
    }
};