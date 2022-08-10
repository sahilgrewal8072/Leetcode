/**https://leetcode.com/jobs/
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
    TreeNode* solve(int start, int end, vector<int> &nums){
        if(start > end)return nullptr;
        int mid = start + (end - start)/2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = solve(start, mid-1, nums);
        head->right = solve(mid+1, end, nums);
        return head;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n-1, nums);
    }
};