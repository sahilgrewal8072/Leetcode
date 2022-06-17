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
    
    bool solve(TreeNode* root, int target, string &s){
        if(root->val == target)return true;
        
        if(root->left && solve(root->left, target, s))
            s.push_back('L');
        else if(root->right && solve(root->right, target, s))
            s.push_back('R');
        
        return !s.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s1;
        string s2; 
        solve(root, startValue, s1);
        solve(root, destValue, s2);
        int i=0;
        cout<<s1<<endl;
        cout<<s2<<endl;
        while(!s1.empty() && !s2.empty() && s1.back() == s2.back()){
            s1.pop_back();
            s2.pop_back();
        }
        
        return string(s1.length(), 'U') + string(rbegin(s2), rend(s2));
    }
};