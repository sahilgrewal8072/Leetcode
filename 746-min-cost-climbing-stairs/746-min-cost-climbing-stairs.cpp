class Solution {
    private:
    int solve(int ind, vector<int> &cost, vector<int> &dp, int n){
        if(ind + 2 >= n)return 0;
        if(dp[ind+1] != -1)return dp[ind + 1];
        int take = 0;
            take = min(cost[ind + 1] + solve(ind + 1, cost, dp, n), cost[ind + 2] + solve(ind + 2, cost, dp, n));
        return dp[ind+1] = take;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return solve(-1, cost, dp, n);
    }
};