class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = 0;
        bool flag = false;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1')flag = true;
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j] - '0';
                    continue;
                }
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1] });
                    
                }else{
                    dp[i][j] = 0;
                }
                mx = max(mx, dp[i][j]);
            }
        }
        if(mx == 0 && flag)return 1;
        return mx*mx;
    }
};