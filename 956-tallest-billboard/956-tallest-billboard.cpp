class Solution {
public:
    
    int solve(int ind1, int sum1, int sum2, vector<int> &rods, vector<vector<int>> &dp, int n){
       if(ind1 == n){
           if(sum1 == sum2)return 0;
           return -1e9;
       }
        if(dp[ind1][abs(sum2 - sum1)] != -1)return dp[ind1][abs(sum2 - sum1)];
        
        return dp[ind1][abs(sum2 - sum1)] = max({rods[ind1] + solve(ind1 + 1, sum1 + rods[ind1], sum2, rods, dp, n), rods[ind1] + solve(ind1+1, sum1, sum2 + rods[ind1], rods, dp, n), solve(ind1 + 1, sum1, sum2, rods, dp, n)});
    }
    
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n, vector<int> (5001, -1));
        return solve(0, 0, 0, rods, dp, n)/2;
    }
};