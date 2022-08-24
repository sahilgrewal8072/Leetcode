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
    void inorderTraversal(TreeNode* root, vector<TreeNode*> &sorted){
        if(!root){
            return;
        }
        
        inorderTraversal(root->left, sorted);
        sorted.push_back(root);
        inorderTraversal(root->right, sorted);
    }
    
    
    private:
    TreeNode* solve(vector<TreeNode*> &sorted, int low, int high){
        if(low > high)return nullptr;
        
        int mid = low + (high - low)/2;
        TreeNode* head = new TreeNode(sorted[mid]->val);
        head->left = solve(sorted, low, mid-1);
        head->right = solve(sorted, mid + 1, high);
        return head;
    }
    
public:
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sorted;
        inorderTraversal(root, sorted);
        return solve(sorted, 0, sorted.size()-1);
    }
};