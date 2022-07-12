class Solution {
    private:
    int solve(int ind, int curr_sum, int mask, int k, int target, int n, vector<int> &nums, vector<int> &dp){
        if(k == 0)return true;
        if(dp[mask] != -1)return dp[mask];
        int ans = 0;
        for(int i=0; i<n; i++){
            if(mask & (1 << i))continue;
            if(curr_sum + nums[i] > target)break;
            if(curr_sum + nums[i] == target){
                mask ^= (1 << i);
                ans = max(ans, solve(ind, 0, mask, k-1, target, n, nums, dp));
                mask ^= (1 << i);
            }else{
                mask ^= (1 << i);
                ans = max(ans, solve(i + 1, curr_sum + nums[i], mask, k, target, n, nums, dp));
                mask ^= (1 << i);
            }
            if(ans == 1)break;
        }
        
        return dp[mask] = ans;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto &it : nums)sum += it;
        if(k > n || sum%k != 0)return false;
        vector<int> dp((1<<16) + 1, -1);
        return solve(0, 0, 0, k-1, sum/k, n, nums, dp);
    }
};