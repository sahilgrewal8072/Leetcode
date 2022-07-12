class Solution {
    private:
    int solve(int sum, int mask, int k, int target, vector<int> &arr, vector<int> &dp, int n){
        if(k == 0)return true;
        if(dp[mask] != -1)return dp[mask];
        int ans = 0;
        for(int i=0; i<n; i++){
            if(mask & (1 << i))continue;
            if(sum + arr[i] > target)break;
            if(sum + arr[i] == target){
                mask ^= (1 << i);
                ans = max(ans,solve(0, mask, k-1, target, arr, dp, n));
                mask ^= (1 << i);
            }else{
                mask ^= (1 << i);
                ans = max(ans, solve(sum + arr[i], mask, k, target, arr, dp, n));
                mask ^= (1 << i);
            }
            
            if(ans == 1)break;
        }
        return dp[mask] = ans;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp((1 << 16) + 1, -1);
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto &it : nums)sum += it;
        if(sum%k != 0 || k > n)return false;
        return solve(0, 0, k-1, sum/k, nums, dp, n);
    }
};