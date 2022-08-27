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
    // MUST revise
    TreeNode* helper(TreeNode* root){
        if(!root->left){
            return root->right;
        }else if(!root->right){
            return root->left;
        }
        
       TreeNode* rt_child = root->right;
        TreeNode* last_rt = find_extreme(root->left);
        last_rt->right = rt_child;
        return root->left;
    }
    
    TreeNode* find_extreme(TreeNode* root){
        if(!root->right)return root;
        return find_extreme(root->right);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                if(root->left != nullptr && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right != nullptr && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};