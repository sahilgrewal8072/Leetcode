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
    int solve(TreeNode* root, unordered_map<int, int> &mp, int &mx_sum){
        if(!root)return 0;
        
        int left = solve(root->left, mp, mx_sum);
        int right = solve(root->right,  mp, mx_sum);
        int sum = root->val + left + right;
        mp[sum]++;
        if(mp[sum] > mx_sum){
            mx_sum = mp[sum];
        }
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        int mx_sum = 0;
        solve(root, mp, mx_sum);
        vector<int> ans;
        for(auto &it : mp){
            if(it.second == mx_sum){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};