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
    //iterative method
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
    
    // recursive method;
    void solve_recur(TreeNode* root, int &sum){
        if(!root)return;
        solve_recur(root->right, sum);
        sum += root->val;
        root->val = sum;
        solve_recur(root->left, sum);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        // solve(root);
        int sum = 0;
         solve_recur(root, sum);
        return root;
    }
};