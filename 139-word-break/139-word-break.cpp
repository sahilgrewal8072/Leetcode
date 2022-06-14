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
        vector<int> dp(n, -1);
        unordered_set<string> st;
        for(auto it : wordDict){
            st.insert(it);
        }
        
        return solve(0, s, st, n, dp);
    }
};