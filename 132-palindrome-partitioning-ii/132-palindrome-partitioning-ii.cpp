class Solution {
    
    
    private:
    void isPali(string &s, vector<vector<bool>> &pali, int &n){
    
        for(int gap = 0; gap < n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(gap == 0){
                    pali[i][j] = true;
                }else if(gap == 1){
                    pali[i][j] = (s[i] == s[j]) ? true : false;
                }else{
                    if(s[i] == s[j] && pali[i+1][j-1] == true){
                        pali[i][j] = true;
                    }
                }
            }
        }    
    }
    
       
    
    
    int solve(int start, int end, string &s, int &n, vector<vector<int>> &dp, vector<vector<bool>> &pali){
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1)return dp[start][end]; 
        if(pali[start][end])return 0;
        
        int mn = 1e8;
        for(int k=start; k<end; k++){
            int left = solve(start, k, s, n, dp, pali);
            int right = solve(k+1, end, s, n, dp, pali);
            mn = min(mn, left + right + 1);
        }
        
        return dp[start][end] = mn;
    }
    
    
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<bool>> pali(n, vector<bool>(n, false));
        isPali(s, pali, n);
        vector<int> suffix(n, 0);
        for(int i = 1; i<n; i++){
            if(pali[0][i]){
                suffix[i] = 0;
            }else{
                int mn = 1e7;
                for(int k=i; k>=1; k--){
                    if(pali[k][i])
                    mn = min(mn, suffix[k-1]);
                }
                suffix[i] = mn + 1;
            }
            
        }
        return suffix[n-1];
    }
};