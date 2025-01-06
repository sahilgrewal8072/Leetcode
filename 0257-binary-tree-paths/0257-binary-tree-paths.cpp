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
    private:
    void solve(TreeNode* root, string curr, vector<string> &ans){
        if(!root)return;
        if(isLeaf(root)){
            curr += "->";
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }
        if(curr.length() > 0){
            curr +=  ("->" + to_string(root->val));
        }else if(curr.length() == 0){
            curr = to_string(root->val);
        }
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(isLeaf(root))return {to_string(root->val)};
        solve(root, "", ans);
        return ans;
    }
};