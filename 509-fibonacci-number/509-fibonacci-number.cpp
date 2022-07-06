class Solution {
public:
    
    int solve_fib(int n, vector<int> &dp){
        if(n <= 1)return dp[n] =  n;
        if(dp[n] != -1)return dp[n];
        return dp[n] = (solve_fib(n-1, dp) + solve_fib(n-2, dp));
    }
    
    int fib(int n) {
        if(n < 2)return n;
        vector<int> dp(n+1, 0);
        // solve_fib(n, dp);
        int ans;
        int pre1 = 0;
        int pre2 = 1;
        for(int i=2; i<=n; i++){
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }
        return ans;
    }
};