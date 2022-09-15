class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n , 0));
        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                if(x == 0 && y == 0){
                    dp[x][y] = grid[0][0];
                    continue;
                }
                int up = INT_MAX;
                int left = INT_MAX;
                if(x > 0)up = dp[x-1][y] + grid[x][y];
                if(y > 0)left = dp[x][y-1] + grid[x][y];
                dp[x][y] = min(up, left);
            }
        }
        return dp[m-1][n-1];
    }
};