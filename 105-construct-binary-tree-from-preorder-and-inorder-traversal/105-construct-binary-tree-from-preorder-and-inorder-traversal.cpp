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
    unordered_map<int, int> mp;
    
     TreeNode* builder(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd, int preStart, int preEnd){
         if(inStart > inEnd || preStart > preEnd)return nullptr;
         
         int myroot = mp[preorder[preStart]];
         TreeNode* root = new TreeNode(preorder[preStart]);
         int diff = myroot - inStart;
         root->left = builder(preorder, inorder, inStart, myroot-1, preStart+1, preStart + diff);
         root->right = builder(preorder, inorder, myroot+1, inEnd, preStart + diff + 1, preEnd);
         return root;
     }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int m = preorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int inStart = 0;
        int preStart = 0;
        int inEnd = n-1;
        int preEnd = m-1;
        return builder(preorder, inorder, inStart, inEnd, preStart, preEnd);
    }
};