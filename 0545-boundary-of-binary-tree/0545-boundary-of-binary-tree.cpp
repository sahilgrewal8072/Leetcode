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
    bool isLeaf(TreeNode* root){
        if(root && !root->left && !root->right)return true;
        return false;
    }

    void solveLeft(TreeNode* root, vector<int> &ans){
        TreeNode* it = root->left;
        while(it){
            if(!isLeaf(it)){
                ans.push_back(it->val);
            }
            if(it->left){
                it = it->left;
            }else{
                it = it->right;
            }

        }
    }

    void solveRight(TreeNode* root, vector<int> &ans){
        TreeNode* it = root->right;
        vector<int> tmp;
        while(it){
            if(!isLeaf(it)){
                tmp.push_back(it->val);
            }
            if(it->right){
                it = it->right;
            }else{
                it = it->left;
            }
        }

        for(int i = tmp.size()- 1; i >= 0; i--){
            ans.push_back(tmp[i]);
        }
    }

    void collectLeaf(TreeNode* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->val);
        }

        if(root->left)collectLeaf(root->left, ans);
        if(root->right)collectLeaf(root->right, ans);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        if(!isLeaf(root))
        ans.push_back(root->val);
        solveLeft(root, ans);
        collectLeaf(root, ans);
        solveRight(root, ans);
        return ans;
    }
};