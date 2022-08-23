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
    TreeNode* build_Tree(vector<int> &preorder, vector<int> &inorder, int in_s, int in_e, int p_s, int p_e, unordered_map<int, int> &mp){
        if(in_s > in_e || p_s > p_e)return nullptr;
        int myroot = mp[preorder[p_s]];
        TreeNode* root = new TreeNode(preorder[p_s]);
        int diff = myroot - in_s;
        root->left = build_Tree(preorder, inorder, in_s, myroot-1, p_s + 1, p_s + diff, mp);
        root->right = build_Tree(preorder, inorder, myroot + 1, in_e, p_s + diff + 1, p_e, mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return build_Tree(preorder, inorder, 0, n-1, 0, n-1, mp);
    }
};