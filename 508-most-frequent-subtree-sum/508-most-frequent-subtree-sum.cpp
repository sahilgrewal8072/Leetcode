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
    int solve(TreeNode* root, unordered_map<int, int> &mp, int &mx_freq){
        if(!root)return 0;
        
        int left = solve(root->left, mp, mx_freq);
        int right = solve(root->right,  mp, mx_freq);
        int sum = root->val + left + right;
        mp[sum]++;
        // if(mp[sum] > mx_sum){
        //     mx_sum = mp[sum];
        // }
        mx_freq = max(mx_freq, mp[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        int mx_freq = 0;
        solve(root, mp, mx_freq);
        vector<int> ans;
        for(auto &it : mp){
            if(it.second == mx_freq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};