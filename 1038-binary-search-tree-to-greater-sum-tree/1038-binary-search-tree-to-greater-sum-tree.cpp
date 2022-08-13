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
        void solve(TreeNode* root){
            stack<TreeNode*> st;
            int sum = 0;
            while(root || !st.empty()){
                while(root){
                    st.push(root);
                    root = root->right;
                }
                root = st.top();
                st.pop();
                sum += root->val;
                root->val = sum;
                root = root->left;
            }
        }
public:
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};