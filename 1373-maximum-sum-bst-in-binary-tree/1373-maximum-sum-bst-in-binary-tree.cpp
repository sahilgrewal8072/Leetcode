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

class BST{
    public:
    bool isBst;
    int t_min;
    int t_max;
    int sum;
    // BST(bool _isBst, int _t_min, int _t_max){
    //     isBst = _isBst;
    //     t_min = _t_min;
    //     t_max = _t_max;
    // }
};

class Solution {
public:
    BST solve(TreeNode* root) {
        if(!root){
            BST temp;
            temp.sum = 0;
            temp.isBst = true;
            temp.t_min = INT_MAX;
            temp.t_max = INT_MIN;
            return temp;
        }
       
        BST lt = solve(root->left);
        BST rt = solve(root->right);
        BST curr;
        curr.t_min = min(root->val, lt.t_min);
        curr.t_max = max(root->val, rt.t_max);
        curr.isBst = lt.isBst && rt.isBst && (root->val > lt.t_max && root->val < rt.t_min);
        
        if(curr.isBst){
            curr.sum = root->val + lt.sum + rt.sum;
        }else{
            curr.sum = max(lt.sum, rt.sum);
        }
        res = max(res, curr.sum);
        return curr;
    }
    
    
    int res = INT_MIN;
    int maxSumBST(TreeNode* root) {
        solve(root);
        return res > 0 ? res : 0;
    }
};