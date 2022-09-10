class Solution {
    private:
    int solve(int curr_sum, int mask, vector<int> &nums, int limit, vector<int> &dp, int &n, int target){
        int ans = 0;
        if(limit == 0)return true;
        if(dp[mask] != -1)return dp[mask];
        for(int i=0; i<n; i++){
            if(curr_sum + nums[i] > target)break;
            if(mask & (1 << i))continue;
            if(curr_sum + nums[i] == target){
                mask ^= (1 << i);
                ans = max(ans, solve(0, mask, nums, limit-1, dp, n, target));
                mask ^= (1 << i);
            }else{
                mask ^= (1 << i);
                ans = max(ans, solve(curr_sum + nums[i], mask, nums, limit, dp, n, target));
                mask ^= (1 << i);
            }
            
            if(ans == 1)break;
        }
        
        return dp[mask] =  ans;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp((1 << 16) + 1, -1);
        for(auto &it : nums){
            sum += it;
        }
        if(k > n || sum%k != 0){
            return false;
        }
        if(k == 1)return true;
        return solve(0, 0, nums, k, dp, n, sum/k);
    }
    
};