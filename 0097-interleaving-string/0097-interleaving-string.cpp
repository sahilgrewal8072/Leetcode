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
                int n1x = s1.length();
                int n2x = s2.length();
                int n3x = s3.length();
                if(n1x + n2x != n3x)return false;
                vector<vector<int>> dp(n1x + 1, vector<int>(n2x + 1, 0));
                // return solve(n1, n2, n3, s1, s2, s3, dp);
                int n3 = 0;
                for(int n1 = 0; n1 <= n1x; n1++){
                    for(int n2 = 0; n2 <= n2x; n2++){
                        n3 = n1 + n2;
                        if(n3 == 0 && (n1 == 0 && n2 == 0)){
                            dp[n1][n2] = true;
                            continue;
                        }
                        if(n3 > 0 && (n1 == 0 && n2 == 0)){
                            dp[n1][n2] = false;
                            continue;
                        }
                        if(n3 == 0 && (n1 > 0 || n2 > 0)){
                            dp[n1][n2] = false;
                            continue;
                        }
                        
                        int take1 = 0;
                        int take2 = 0;
                        if(n1 > 0 && n2 > 0 && n3 > 0 && (s1[n1 - 1] == s3[n3 - 1] && s2[n2-1] == s3[n3-1])){
                            dp[n1][n2] = dp[n1 - 1][n2] || dp[n1][n2-1];
                            continue;
                        }else if(n1 > 0 && n3 > 0 && (s1[n1-1] == s3[n3-1])){
                            take1 = dp[n1-1][n2];
                        }else if(n2 > 0 && n3 > 0 && (s2[n2-1] == s3[n3-1])){
                            take2 = dp[n1][n2-1];
                        }
                        dp[n1][n2] = take1 || take2;
                        
                    }
                }
                return dp[n1x][n2x];
    }
};