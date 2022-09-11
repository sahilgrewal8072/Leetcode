class Solution {
    private:
    int solve(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if(n == 0 || m == 0){
            return 0;
        }
        
        if(dp[n][m] != -1)return dp[n][m];
        
        if(s1[n-1] == s2[m-1]){
            return dp[n][m] =   1 + solve(n-1, m-1, s1, s2, dp);
        }else{
            return dp[n][m] = max(solve(n-1, m, s1, s2, dp), solve(n, m-1, s1, s2, dp));
        }
    }
    
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        // return solve(n, m, s1, s2, dp);
        for(int ind1 = 1; ind1 <=n; ind1++){
            for(int ind2 = 1; ind2 <= m; ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                         curr[ind2] =  1 + prev[ind2-1];
                }else{
                         curr[ind2] = max(prev[ind2], curr[ind2-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};