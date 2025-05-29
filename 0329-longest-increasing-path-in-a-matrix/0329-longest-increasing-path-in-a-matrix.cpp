class Solution {
    private:
    int dfs(int i, int j, int prev, vector<vector<int>> &grid, int m, int n, int dx[], int dy[], vector<vector<int>> &dp){
        int mx = 0;
        int count = 1;
        if(dp[i][j] != -1)return dp[i][j];
        for(int ind=0; ind<4; ind++){
            int nx = i + dx[ind];
            int ny = j + dy[ind];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] > grid[i][j]){
                count = max(count, 1 + dfs(nx, ny, grid[i][j], grid, m, n, dx, dy, dp));
            }
        }
        
        return dp[i][j] = count;
    }
    
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mx = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mx = max(mx, dfs(i, j, -1, matrix, m, n, dx, dy, dp));
            }
        }
        
        return mx;
    }
};