class Solution {
    private:
    int solve(int ind, int prev, int target, vector<int> &houses, vector<vector<int>> &cost, int m, int n, vector<vector<vector<int>>> &dp){
        if(ind >= m && target == 0){
            return 0;
        }
        if(ind >= m){
            return 1e7;
        }
        
        if(target < 0){
            return 1e7;
        }
        
        if(dp[ind][prev][target]  != -1)return dp[ind][prev][target];
        int mn = 1e7;
        if(houses[ind] != 0){
            if(prev == houses[ind])
            return dp[ind][prev][target] = solve(ind + 1, houses[ind], target, houses, cost, m, n, dp);
            else
                return dp[ind][prev][target] = solve(ind + 1, houses[ind], target-1, houses, cost, m, n, dp);
        }
            for(int i=1; i<=n; i++){
            if(houses[ind] == 0){
                int x = target;
                if(prev != i)x--;
                 mn = min(mn, cost[ind][i-1] + solve(ind + 1, i, x, houses, cost, m, n, dp));
                }
            }    
        return dp[ind][prev][target] = mn;
    }
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(105, vector<vector<int>>(25, vector<int>(105, -1)));
        int x = solve(0, 0, target, houses, cost, m, n, dp);
        if(x == 1e7)return -1;
        return x;
    }
};