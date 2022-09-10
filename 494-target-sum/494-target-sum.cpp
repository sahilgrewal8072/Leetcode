class Solution {
    private:
    int solve(int n, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(n == 0){
            if(target == 0)return 1;
            return 0;
        }
        if(dp[n][target] != -1)return dp[n][target];
        if(target >= nums[n-1]){
            return dp[n][target] = solve(n-1, nums, target - nums[n-1], dp) + solve(n-1, nums, target, dp);
        }else{
            return dp[n][target] = solve(n-1, nums, target, dp);  
        }
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        int newTarget = abs(sum + target);
        if(newTarget/2 > sum || newTarget&1)return 0;
        vector<vector<int>> dp(n + 1, vector<int> (newTarget/2  + 1, 0));
        // return solve(n, nums, newTarget/2, dp);
        dp[0][0] = 1;
        for(int ind=1; ind<=n; ind++){
            for(int sum = 0; sum <= newTarget/2; sum++){
                 if(sum >= nums[ind-1]){
                     dp[ind][sum] = dp[ind-1][sum - nums[ind-1]] + dp[ind-1][sum];
                }else{
                    dp[ind][sum] = dp[ind-1][sum];  
                }
            }
        }
        return dp[n][newTarget/2];
    }
};