class Solution {
public:
    
    int solve(int x, int y, int dx[], int dy[], vector<vector<int>>& grid,  vector<vector<int>> &visited, int &count, int n, int m){
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny  = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && grid[nx][ny] == 1){
                count += 1;
                solve(nx, ny, dx, dy, grid, visited, count, n, m);
            }
        }
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    int count = 1;
                    mx = max(mx, solve(i, j, dx, dy, grid,visited, count, n, m));
                }
            }
        }
        return mx;
    }
};