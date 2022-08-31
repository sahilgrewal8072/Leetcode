class Solution {
    private:
    vector<vector<int>> ans;
    vector<vector<bool>> pac, alt;
   
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &heights, int dx[], int dy[], int m, int n){
        if(visited[i][j])return;
            visited[i][j] = true;
        if(pac[i][j] && alt[i][j]){
            ans.push_back(vector<int>{i, j});
        }
        
        for(int ind=0; ind < 4; ind++){
            int nx = i + dx[ind];
            int ny = j + dy[ind];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && heights[i][j] <= heights[nx][ny]){
                dfs(nx, ny, visited, heights, dx, dy, m, n);
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
         int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        pac = alt = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            dfs(i, 0, pac, heights, dx, dy, m, n), dfs(i, n-1, alt, heights, dx, dy, m, n);
        }
        
        for(int i=0; i<n; i++){
            dfs(0, i, pac, heights, dx, dy, m, n), dfs(m-1, i, alt, heights, dx, dy, m, n);
        }
        return ans;
    }
};