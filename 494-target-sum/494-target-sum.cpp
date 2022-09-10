class Solution {
public:
    
    
    int solve(int n, vector<int> &nums, int target, int sum, vector<vector<int>> &dp){
        if(n == 0){
            if(target == sum){
                return 1;
            }
            return 0;
        }
        
        // if target becomes -ve + 100 will help to shift the index
        if(dp[n][sum + 1000] != -1)return dp[n][sum + 1000];
        return dp[n][sum + 1000] = (solve(n-1, nums, target, sum - nums[n-1], dp) + solve(n-1, nums, target, sum + nums[n-1], dp));
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2005, -1));
       return solve(n, nums, target, 0, dp);
    }
};