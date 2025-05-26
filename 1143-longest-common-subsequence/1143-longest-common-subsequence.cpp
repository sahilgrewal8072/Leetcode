class Solution {
     int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(s1[ind1-1] == s2[ind2 - 1]){
            return dp[ind1][ind2] =  1 + solve(ind1 - 1, ind2 - 1, s1, s2, dp);
        }
            return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s1, s2, dp), solve(ind1, ind2-1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2 + 1, -1));
        return solve(n1, n2, text1, text2, dp);
    }
};