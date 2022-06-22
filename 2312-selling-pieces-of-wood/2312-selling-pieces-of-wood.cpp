class Solution {
    
    private:
    long long solve(int m, int n, vector<vector<int>> &cost, vector<vector<long long>> &dp){
        if(m < 0 || n < 0){
            return -1e8;    
        }   
        
        if(dp[m][n] != -1)return dp[m][n];
        long long  price = cost[m][n];
        // partition vertically
        for(int h = 1; h < m; h++){
            price = max(price, solve(m-h, n, cost, dp) + solve(h, n, cost, dp));
        }
        
        for(int w = 1; w < n; w++){
            price =  max(price, solve(m, n-w, cost, dp) + solve(m, w, cost, dp));
        }
        return dp[m][n] = price;
    }
    
    
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {

        vector<vector<int>> cost(m + 1, vector<int>(n + 1, 0));
        vector<vector<long long>> dp(m+1, vector<long long>(n+1,-1));
        for(auto &it : prices){
            int x = it[0];
            int y = it[1];
            cost[x][y] = it[2];
        }
        return solve(m, n, cost, dp);
    }
};