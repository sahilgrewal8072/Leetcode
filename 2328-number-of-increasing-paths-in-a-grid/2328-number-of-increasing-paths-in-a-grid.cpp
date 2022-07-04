const int M = 1e9 + 7;
class Solution {  
private:
    int dfs(int i, int j, vector<vector<int>> &grid, int m, int n, int dx[], int dy[], vector<vector<long long>> &dp){
        long long count = 1;
        if(dp[i][j] != -1)return dp[i][j];
        for(int ind=0; ind<4; ind++){
            int nx = i + dx[ind];
            int ny = j + dy[ind];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n  && grid[nx][ny] > grid[i][j]){
                count +=  (dfs(nx, ny, grid, m, n, dx, dy, dp)%M)%M;
            }
        }      
        return dp[i][j] = count%M;
    }
        
public:    
    int countPaths(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
        long long sum = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum += dfs(i, j, matrix, m, n, dx, dy, dp)%M;
                sum %= M;
            }
        }      
        return sum%M;
    }
};