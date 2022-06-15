class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
        int mx = 0;
        int result = 0;
        bool flag = false;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j];
                    if(matrix[i][j] == 1)result++;
                    continue;
                }
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min({dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1] });
                    result += dp[i][j];
                }
            }
        }
        return result;
       
    }
};