class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirX[4] = {-1, 1, 0, 0};
        int dirY[4] = {0, 0, -1, 1};
        int count = 0;
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    grid[i][j] = '0';
                    q.push({i, j});
                    
                    while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                for(int i=0; i<4; i++){
                    int nx = x + dirX[i];
                    int ny = y + dirY[i];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1'){
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
                }
                
            }
                }
        
        return count;
    }
};