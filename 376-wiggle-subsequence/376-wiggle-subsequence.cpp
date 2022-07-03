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
       vector<int> nxt(2, 0), curr(2, 0);
        for(int ind = n-1; ind>0; ind--){
            for(int state = 0; state <= 1; state++){
                int take = 0;
                if(nums[ind] - nums[ind-1] < 0 && state == 1 || nums[ind] - nums[ind-1] > 0 && state == 0){
                    curr[state] =  1 + nxt[!state];
                }else
                curr[state] = 0 + nxt[state];
            }
            nxt = curr;
        }
        return 1 + max(nxt[1], nxt[0]);
    }
};