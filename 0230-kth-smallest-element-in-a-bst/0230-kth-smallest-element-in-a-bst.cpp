class Solution {
    private: 
        void inorder(TreeNode* root, int &count, int &ans){
            if(!root)return;
            inorder(root->left, count, ans);
            count--;
            if(count == 0){
                ans = root->val;
                return;
            }
            inorder(root->right, count, ans);
        }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};