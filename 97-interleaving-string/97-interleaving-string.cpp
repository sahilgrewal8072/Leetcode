class Solution {
    private:
    bool solve(int ind1, int ind2, int ind3, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        
       if(ind3 < 0 && (ind1 >= 0 || ind2 >= 0))return false;
        if(ind1 < 0  && ind2 < 0 )return true;
    if( dp[ind1 + 1][ind2 + 1] != -1)return dp[ind1 + 1][ind2 + 1];
        int take1 = 0;
        int take2 = 0;
        if(ind1 >= 0 && ind2 >= 0 && s1[ind1] == s3[ind3] && s2[ind2] == s3[ind3]){
            return dp[ind1 + 1][ind2 + 1] = (solve(ind1-1, ind2, ind3-1, s1, s2, s3, dp) || solve(ind1, ind2-1, ind3-1, s1, s2, s3, dp));
        }else if(ind1 >= 0 && s1[ind1] == s3[ind3]){
            take1 = solve(ind1-1, ind2, ind3-1, s1, s2, s3, dp);
        }else if(ind2 >= 0 && s2[ind2] == s3[ind3]){
            take2 = solve(ind1, ind2-1, ind3-1, s1, s2, s3, dp);
        }
        
        return (take1 || take2);
    }
    
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int l = s2.length();
        int m = s3.length();
        vector<vector<int>> dp(n+1, vector<int>(l+1, -1));
        if(n + l != m)return false;
        return solve(n-1, l-1, m-1, s1, s2, s3, dp);
    }
};