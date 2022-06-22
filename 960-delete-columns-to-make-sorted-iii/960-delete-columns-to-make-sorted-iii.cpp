class Solution {
    private:
    int solve(int ind, int prev, vector<string>&strs, int n, int m, vector<vector<int>> &dp){
        if(ind >= n){
            return 0;
        }
        
        if(dp[ind][prev + 1] != -1)return dp[ind][prev+1];
        
        int notake =  0 + solve(ind + 1, prev, strs, n, m, dp);
        bool flag = false;
        for(int i = 0; i<m; i++){
            if(prev == -1)break;
            if(strs[i][ind] < strs[i][prev]){
                flag = true;
                break;
            }
        }
        int take = -1;
        if(!flag){
            take = 1 + solve(ind + 1, ind, strs, n, m, dp);
        }
        
        return dp[ind][prev + 1] = max(take, notake);
    }
    
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        int  m = strs.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
        return n - solve(0, -1, strs, n, m, dp);
    }
};