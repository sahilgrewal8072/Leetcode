class Solution {
    private:
    int solve(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp){
        
        if(ind == 0){
           if(sum == 0 && nums[ind] == 0){
               return 2;
           }else if(nums[ind] == sum || sum == 0){
               return 1;
           }else{
               return 0;
           }
        }
        
        if(dp[ind][sum] != -1)return dp[ind][sum];
        int pick = 0;
        if(nums[ind] <= sum)
        pick = solve(ind - 1, sum - nums[ind], nums, dp);
        int nopick = solve(ind - 1, sum, nums, dp);
        return dp[ind][sum] = pick + nopick;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
            int total = 0;
        for(int i = 0; i<n; i++){
            total += nums[i];
        }
        if(abs(target) > total)return 0;
        int s1 = abs(target + total); 
        // if((target + total)%2 != 0 || s1/2 > total)return 0; //doubt
        if((total - target) < 0 || (total - target)%2)return 0;
        vector<vector<int>> dp(n, vector<int>((total - target)/2 + 1, -1));
        return solve(n-1, (total - target)/2, nums, dp);
    }
};