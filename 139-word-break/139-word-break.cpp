class Solution {
public:
    
    bool solve(int ind, string &s, unordered_set<string> &st, int n, vector<int> &dp){
        if(ind >= n)return true;
        if(dp[ind] != -1)return dp[ind];
        string sub = "";
        for(int i = ind; i < n; i++){
            if(st.count(sub += s[i]) > 0 && solve(i + 1, s, st, n, dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        unordered_set<string> st;
        for(auto it : wordDict){
            st.insert(it);
        }
        
        dp[n] = 1;
        for(int ind = n-1; ind >= 0; ind--){
            string sub = "";
            bool flag = false;
            for(int i = ind; i < n; i++){
                if(st.count(sub += s[i]) > 0 && dp[i + 1] == 1){
                    dp[ind] = 1;
                    flag = true;
                }
            }
            if(!flag)
            dp[ind] = 0;
        }
        
        return dp[0];
        // return solve(0, s, st, n, dp);
    }
};