class Solution {
public:
    
    // vector<int> arr = {1, 2, 3, 4, 5, 6};
    long long mod = 1e9 + 7;
    int solve(int prev, int pprev, int n, vector<vector<vector<long long>>> &dp){
        if(n == 0){
            return 1;
        }
        
        if(dp[n][prev][pprev] != -1)return dp[n][prev][pprev];
        long long take = 0;
        for(int i=1; i<=6; i++){
            if(i != prev && i != pprev && (prev == 0 || gcd(i, prev) == 1)){
                take += 1ll*(solve(i, prev, n-1, dp)%mod)%mod;
            }
        }
        return dp[n][prev][pprev] = take%mod;
    }
    
    int distinctSequences(int n) {
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(7, vector<long long>(7, -1)));
        return solve(0, 0, n, dp);
    }
};