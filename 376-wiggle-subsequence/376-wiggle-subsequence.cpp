class Solution {
public:
    
    int solve(int ind, int state, vector<int> &nums, vector<vector<int>> &dp, int n){
        if(ind == n)return 0;
        if(dp[ind][state] != -1)return dp[ind][state];
        int take = 0;
        if(nums[ind] - nums[ind-1] < 0 && state == 1 || nums[ind] - nums[ind-1] > 0 && state == 0){
            return dp[ind][state] =  1 + solve(ind + 1, !state, nums, dp, n);
        }
        return dp[ind][state] = 0 + solve(ind + 1, state, nums, dp, n);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2){
            if(n == 1)return 1;
            if(nums[0] == nums[1])return 1;
            return 2;
        }
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // int mx = 0;
        // for(int i=0; i<=1; i++){
        //     mx = max(mx, solve(1, i, nums, dp, n));
        // }
        // return mx + 1;
        for(int ind = n-1; ind>0; ind--){
            for(int state = 0; state <= 1; state++){
                int take = 0;
                if(nums[ind] - nums[ind-1] < 0 && state == 1 || nums[ind] - nums[ind-1] > 0 && state == 0){
                    dp[ind][state] =  1 + dp[ind + 1][!state];
                }else
                dp[ind][state] = 0 + dp[ind + 1][state];
            }
        }
        return 1 + max(dp[1][1], dp[1][0]);
    }
};