class Solution {
    private:
    int solve(int n, vector<int> &cost, vector<int> &dp){
        if(n <= 1){
            return 0;
        }

        if(dp[n] != -1)return dp[n];
        int one = 1e9;
        int two = 1e9;
        if(n - 2 >= 0){
            two = solve(n - 2, cost, dp) + cost[n-2];
        }
        if(n - 1 >= 0)
        one = solve(n-1, cost, dp) + cost[n-1];
        return dp[n] = min(one, two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return solve(n, cost, dp);
    }
};