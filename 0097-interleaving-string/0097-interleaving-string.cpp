class Solution {
    bool solve(int n1, int n2, int n3, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(n3 == 0 && (n1 == 0 && n2 == 0))return true;
        if(n3 > 0 && (n1 == 0 && n2 == 0))return false;
        if(n3 == 0 && (n1 > 0 || n2 > 0))return false;
        if(dp[n1][n2] != -1)return dp[n1][n2];
        int take1 = 0;
        int take2 = 0;
        if(n1 > 0 && n2 > 0 && n3 > 0 && (s1[n1 - 1] == s3[n3 - 1] && s2[n2-1] == s3[n3-1])){
            return dp[n1][n2] = solve(n1 - 1, n2, n3-1, s1, s2, s3, dp) || solve(n1, n2-1, n3-1, s1, s2, s3, dp);
        }else if(n1 > 0 && n3 > 0 && (s1[n1-1] == s3[n3-1])){
            take1 = solve(n1-1, n2, n3-1, s1, s2, s3, dp);
        }else if(n2 > 0 && n3 > 0 && (s2[n2-1] == s3[n3-1])){
            take2 = solve(n1, n2-1, n3-1, s1, s2, s3, dp);
        }
        return dp[n1][n2] = take1 || take2;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
                int n1 = s1.length();
                int n2 = s2.length();
                int n3 = s3.length();
                if(n1 + n2 != n3)return false;
                vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
                return solve(n1, n2, n3, s1, s2, s3, dp);
    }
};