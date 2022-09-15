class Solution {
    private:
    int solve(int i, int j, vector<vector<char>>& matrix, int &m, int &n, int &mx, vector<vector<int>> &dp){
        if(i >= m || j >= n){
            return 0;
        }
        
        int right = solve(i, j + 1, matrix, m, n, mx, dp);
        int down = solve(i+1, j, matrix, m, n, mx, dp);
        int diagonal = solve(i + 1, j + 1, matrix, m, n, mx, dp);
        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min({right, down, diagonal});
            mx = max(mx, dp[i][j]);
            return dp[i][j];
        }
        return dp[i][j] = 0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mx = 0;
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        // solve(0, 0, matrix, m, n, mx, dp);
        for(int i = m - 1; i>= 0; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                int right = dp[i][j + 1];
                int down = dp[i+1][j];
                int diagonal = dp[i + 1][j + 1];
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({right, down, diagonal});
                        mx = max(mx, dp[i][j]);
                }else
                 dp[i][j] = 0;
            }
        }
        return mx*mx;
    }
};