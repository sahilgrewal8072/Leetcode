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
    stack<TreeNode*> st1, st2;
    
    void fill_asc(TreeNode* root) {
        // node.clear();
        TreeNode* curr = root;
        while(curr){
            st1.push(curr);
            curr = curr->left;
        }
    }
    
    int next_grt() {
        int x = -1;
        TreeNode* curr = nullptr;
        if(!st1.empty()){
            curr = st1.top();
            x = st1.top()->val;
            st1.pop();
            if(curr->right){
                curr = curr->right;
                while(curr){
                st1.push(curr);
                curr = curr->left;
                }
            }
        }
        return x;
    }
    
    void fill_dsc(TreeNode* root){
        TreeNode* curr = root;
        while(curr){
            st2.push(curr);
            curr = curr->right;
        }
    }
    
    int next_sml(){
        int x = -1;
        TreeNode* curr = nullptr;
        if(!st2.empty()){
            curr = st2.top();
            x = curr->val;
            st2.pop();
            if(curr->left){
                curr = curr->left;
                while(curr){
                    st2.push(curr);
                    curr = curr->right;
                }
            }
        }
        return x;
    }
    
    bool findTarget(TreeNode* root, int k) {
        fill_asc(root);
        fill_dsc(root);
        int left = next_grt();
        int right = next_sml();
        while(left < right){
            if(left + right == k){
            return true;
        }else if(left + right < k){
            left = next_grt();
        }else{
            right = next_sml();
        }
        }
        
        return false;
    }
};