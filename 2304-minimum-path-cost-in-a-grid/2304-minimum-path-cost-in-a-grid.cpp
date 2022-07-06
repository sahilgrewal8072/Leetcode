class Solution {
    
    private:
    int solve(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &moveCost, int m, int n, int dy[], vector<vector<int>> &dp){
        if(x == m-1){
            // return 0;
            return grid[x][y];    
        }
        if(dp[x][y] != -1)return dp[x][y];
        int mn = 1e9;
        for(int i=0; i<=2*n; i++){
            int nx = x + 1;
            int ny = y + dy[i];
            if(ny >= 0 && ny < n){        
                mn = min(mn, grid[x][y] + moveCost[grid[x][y]][ny] + solve(nx, ny, grid, moveCost, m, n, dy, dp));
            }
        }
        
        return dp[x][y] = mn;
    }
    
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mn = 1e9;
        int j = 0;
        int dy[2*n + 1];
        int k = 1;
        for(j=0; j<n; j++){
            dy[j] = -1*k;
            k++;
        }
        dy[j] = 0;
        j++;
         k = 1;
        for(j; j<=2*n; j++)dy[j] = k++;
        for(int i=0; i<n; i++){
            mn = min(mn, solve(0, i, grid, moveCost, m, n, dy, dp));
        }
        return mn;
    }
};