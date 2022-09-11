class Solution {
    private:
    int solve(int ind, int limit, vector<int> &coins, vector<vector<int>> &dp){
        if(limit == 0){
            return 0;
        }
        
        if(ind == 0){
            return 1e8;
        }
        
        if(dp[ind][limit] != -1)return dp[ind][limit];
        
        int take = 1e8;
        int notake = 1e8;
        if(limit >= coins[ind-1]){
            return dp[ind][limit] = min(1 + solve(ind, limit - coins[ind-1], coins, dp), solve(ind - 1, limit, coins, dp));
        }else{
            return dp[ind][limit] = solve(ind - 1, limit, coins, dp);
        }
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount + 1, -1));
        int ans = solve(n, amount, coins, dp);
        if(ans >= 1e8)return -1;
        return ans;
    }
};