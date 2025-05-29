class Solution {
    private:
    int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
        if(ind2 < 0)return 1;
        if(ind1 < 0)return 0;
        
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        
        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = solve(ind1 - 1, ind2, s, t, dp) + solve(ind1 - 1, ind2 - 1, s, t, dp);
        }
        return dp[ind1][ind2] =  solve(ind1 - 1, ind2, s, t, dp);
    }
    
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0));
        // return solve(n-1, m-1, s, t, dp);
        for(int ind1 = 0; ind1 <= n; ind1++){
            for(int ind2 = 0; ind2 <= m; ind2++){
                if(ind2 == 0){
                    dp[ind1][ind2] = 1;
            }else if(ind1 == 0){
                    dp[ind1][ind2] = 0;  
            }else{
                             if(s[ind1-1] == t[ind2-1]){
                                dp[ind1][ind2] = dp[ind1 - 1][ind2] + dp[ind1 - 1][ind2 - 1];
                            }else{
                                  dp[ind1][ind2] =  dp[ind1 - 1][ind2];
                             }    
                }
            }
        }
        return dp[n][m];
    }
};