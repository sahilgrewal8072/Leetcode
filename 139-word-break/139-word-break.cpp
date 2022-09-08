class Solution {
    private:
        bool solve(int ind, unordered_set<string> &st, string &s, int n, vector<int> &dp){
            if(ind >= n)return true;
            if(dp[ind] != -1)return dp[ind];
            string curr = "";
            for(int i=ind; i<n; i++){
                curr += s[i];
                if(st.count(curr) > 0 && solve(i + 1, st, s, n, dp)){
                   return dp[ind] = true;
                }
            }       
           return dp[ind] = false;
        }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        
        for(auto it : wordDict){
            st.insert(it);
        }
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, st, s, n, dp);
    }
};