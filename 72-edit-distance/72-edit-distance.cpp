class Solution {
    private:
    int solve(int ind1, int ind2, string word1, string word2, vector<vector<int>> &dp){
        if(ind1 == 0){
            return ind2;
        }
        
        if(ind2 == 0){
            return ind1;
        }
        
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        
        int mn = 1e8;
        if(word1[ind1-1] == word2[ind2-1]){
            return solve(ind1-1, ind2-1, word1, word2, dp);
        }else{
            int replaced = 1 + solve(ind1-1, ind2-1, word1, word2, dp);
            int deleted = 1 + solve(ind1-1, ind2, word1, word2, dp);
            int inserted = 1 + solve(ind1, ind2-1, word1, word2, dp);
            mn = min({mn, replaced, deleted, inserted});
        }
        
        return dp[ind1][ind2] = mn;
    }
    
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m + 1, -1));
        return solve(n, m, word1, word2, dp);
    }
};