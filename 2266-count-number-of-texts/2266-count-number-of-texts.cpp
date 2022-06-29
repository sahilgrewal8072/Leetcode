const int M = 1e9 + 7;
class Solution {
public:
    
    int solve(string &s, int n, int ind, vector<int> &dp){
        if(ind >= n)return 1;
        if(dp[ind] != -1)return dp[ind];
        int ans = 0;
        if(ind + 1 < n && s[ind] == s[ind+1]){
            ans += solve(s, n, ind+2, dp);
            ans %= M;
            if(ind + 2 < n && s[ind] == s[ind+2]){
                ans += solve(s, n, ind + 3, dp);
                ans %= M;
                if(ind + 3 < n && s[ind] == s[ind + 3] && (s[ind] == '7' || s[ind] == '9')){
                    ans += solve(s, n, ind + 4, dp);
                    ans %= M;
                }
            }
        }
        ans += solve(s, n, ind + 1, dp);
        return dp[ind] = ans%M;
    }
    
    int countTexts(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        // return solve(mobile, n, 0, dp);
        dp[n] = 1;
        for(int ind = n-1; ind >= 0; ind--){
             int ans = 0;
        if(ind + 1 < n && s[ind] == s[ind+1]){
            ans += dp[ind+2];
            ans %= M;
            if(ind + 2 < n && s[ind] == s[ind+2]){
                ans += dp[ind + 3];
                ans %= M;
                if(ind + 3 < n && s[ind] == s[ind + 3] && (s[ind] == '7' || s[ind] == '9')){
                    ans += dp[ind + 4];
                    ans %= M;
                }
            }
        }
        ans += dp[ind + 1];
         dp[ind] = ans%M;
        }
        return dp[0];
    }
};