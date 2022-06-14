class Solution {
public:
    
    int solve(int ind, string &s, vector<int> &dp, int n){
        if(ind < n && s[ind] == '0')return 0;
        if(ind >= n)return 1;
        if(dp[ind] != -1)return dp[ind];
        
        // pick one ele
        int ways = solve(ind + 1, s, dp, n);
        
        // pick pairs
        if(ind + 1 < n && ((s[ind] == '1' && s[ind+1] <= '9') || (s[ind] == '2' && s[ind+1] < '7'))){
            ways += solve(ind + 2, s, dp, n);
        }
        
        return dp[ind] = ways;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dp, n);
    }
};