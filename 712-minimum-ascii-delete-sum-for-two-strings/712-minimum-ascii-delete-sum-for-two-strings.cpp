class Solution {
    
    private:
    
    int solve(int ind1, int ind2, string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if(ind1 == n || ind2 == m){
            return 0;
        }
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        int notake = max(solve(ind1 + 1, ind2, s1, s2, n, m, dp) , solve(ind1, ind2 + 1, s1, s2, n, m, dp));
        int take = 0;
        if(s1[ind1] == s2[ind2]){
            take = (s1[ind1] - 0) + solve(ind1 + 1, ind2 + 1, s1, s2, n, m, dp);
        }
        
        return dp[ind1][ind2] =  max(take, notake);
    }
    
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m + 1, -1));
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<n; i++){
            sum1 += (s1[i] - 0);
        }
        
        for(int i=0; i<m; i++){
            sum2 += (s2[i] - 0);
        }
        int x = solve(0, 0, s1, s2, n, m, dp);
        return sum1 + sum2 - 2*x;
    }
};