class Solution {
    private:
    int solve(int ind, int buy, int n, vector<int> &prices, vector<vector<int>> &dp){
        if(ind >= n){
            return 0;
        }
        
        if(dp[ind][buy] != -1)return dp[ind][buy];
        
        if(buy){
            return dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, n, prices, dp), 0 + solve(ind + 1, 1, n, prices, dp));
        }else{
            return dp[ind][buy] = max(prices[ind] + solve(ind + 2, 1, n, prices, dp), 0 + solve(ind + 1, 0, n, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> next(2, 0), curr(2, 0), next2(2, 0);
        // return solve(0, 1, n, prices, dp);
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                 if(ind >= n){
                    curr[buy] =  0;
                 }else{
                      if(buy){
                                curr[buy] = max(-prices[ind] + next[0], 0 + next[1]);
                            }else{
                                int amount = 0;
                                if(ind + 2 <= n){
                                    amount = next2[1];
                                }
                                curr[buy] = max(prices[ind] + amount, 0 + next[0]);
                            }
                 }
                           
            }
            next2 = next;
            next = curr;
        }
            return next[1];
        }
};