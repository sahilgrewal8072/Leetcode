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
        // vector<vector<int>> dp(n + 1, vector<int> (newTarget/2  + 1, 0));
        vector<int> prev(newTarget/2 + 1, 0);
        prev[0] = 1;
        // return solve(n, nums, newTarget/2, dp);
        // dp[0][0] = 1;
        for(int ind=1; ind<=n; ind++){
            vector<int> curr(newTarget/2 + 1, 0);
            for(int sum = 0; sum <= newTarget/2; sum++){
                 if(sum >= nums[ind-1]){
                     curr[sum] = prev[sum - nums[ind-1]] + prev[sum];
                }else{
                    curr[sum] = prev[sum];  
                }
            }
            prev = curr;
        }
        return prev[newTarget/2];
    }
};