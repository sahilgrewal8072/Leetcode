class Solution {
    private:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount == 0)return 0;
            if(amount >= coins[ind]){
                if(amount%coins[ind] == 0){
                    return amount/coins[ind];
                }
            }
            return 1e8;
        }
        if(dp[ind][amount] != -1)return dp[ind][amount];
        int take = 1e8;
        int notake = 1e8;

        if(coins[ind] <= amount){
            take = 1 + solve(ind, amount - coins[ind], coins, dp);
        }
        notake = 0 + solve(ind - 1, amount, coins, dp);
        return dp[ind][amount] = min(take, notake);
    }
public:
    int coinChange(vector<int>& coins, int final_amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(final_amount + 1, 0));
        // int ans =  solve(n-1, amount, coins, dp);
        vector<int> prev(final_amount + 1, 0), curr(final_amount + 1, 0);
        
        for(int ind = 0; ind < n; ind++){
            for(int amount = 1; amount <= final_amount; amount++){
                if(ind == 0){ 
                    curr[amount] = 1e8;
                if(amount >= coins[ind]){
                    if(amount%coins[ind] == 0){
                        curr[amount] = amount/coins[ind];
                    }
                } 
                continue;
            }
                
                int take = 1e8;
                int notake = 1e8;

                if(coins[ind] <= amount){
                    take = 1 + curr[amount - coins[ind]];
                }
                notake = 0 + prev[amount];
                 curr[amount] = min(take, notake);
            }
            prev = curr;
        }
        if(prev[final_amount] >= 1e8)return -1;
        // cout<<dp[final_amount]<<endl;
        return prev[final_amount];
    }
};