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
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int mx = 0;
        for(int i=0; i<=1; i++){
            mx = max(mx, solve(1, i, nums, dp, n));
            // cout<<mx<<endl;
        }
        return mx + 1;
    }
};