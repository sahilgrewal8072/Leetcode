class Solution {
public:
    
    void dfs(int x, int y, int dx[], int dy[], vector<vector<int>> &grid, vector<vector<int>> &visited, queue<pair<int, int>> &q, int m, int n){
        visited[x][y] = 1;
        q.push({x, y});
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0 && grid[nx][ny] == 1){
                dfs(nx, ny, dx, dy, grid, visited, q, m, n);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        bool flag = false;
        for(int i=0; i<n; i++){
            if(flag)break;
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    dfs(i, j, dx, dy, grid, visited, q, m, n);
                    flag = true;
                    break;
                }
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                 for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m  && visited[nx][ny] == 0){
                        if(grid[nx][ny] == 1){
                            return count;
                        }
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};