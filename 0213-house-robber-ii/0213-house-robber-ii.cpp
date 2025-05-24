class Solution {
    private:
  int solve(int ind, int n, vector<int> &nums, vector<int> &dp){
        if(ind >= n){
            return 0;
        }

        if(dp[ind] != -1)return dp[ind];

        int take = INT_MIN;
        int notake = INT_MIN;

        take  = nums[ind] + solve(ind + 2, n, nums, dp);
        notake = 0 + solve(ind + 1, n, nums, dp);
        return dp[ind] = max(take, notake);
    }

    int solve_itr(int start, int end, vector<int> &nums){
        // vector<int> dp(end  + 3, 0);
        int nxt = 0;
        int nxt_nxt = 0;
        dp[end] = 0;
        int curr = 0;
        for(int ind = end; ind>=start; ind--){
             int take = INT_MIN;
            int notake = INT_MIN;

            take  = nums[ind] + nxt_nxt;
            notake = 0 + nxt;
            curr = max(take, notake);
            nxt_nxt = nxt;
            nxt = curr;
        }   
        return nxt;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int> dp(n, -1);
        vector<int> dp1(n, -1);
        // return max(solve(0, n-, nums, dp), solve(1, n, nums, dp1));
        return max(solve_itr(0, n-2, nums), solve_itr(1, n-1, nums));
    }
};