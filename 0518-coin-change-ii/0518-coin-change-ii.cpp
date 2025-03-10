class Solution {
    private:
    int solve(int ind, int target, vector<vector<int>> &dp, vector<int> &coins){
        if(target == 0)return 1;
        if(ind < 0)return 0;
        if(dp[ind][target] != -1)return dp[ind][target];
        int pick = 0;
        if(coins[ind] <= target){
            pick = solve(ind, target - coins[ind], dp, coins);
        }
        int nopick = 0;
        nopick = solve(ind - 1, target, dp, coins);
        return dp[ind][target] = pick + nopick;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n-1, amount, dp, coins);
    }
};