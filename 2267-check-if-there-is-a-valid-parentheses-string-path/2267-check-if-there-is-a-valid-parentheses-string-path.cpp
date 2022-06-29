class Solution {
public:
    
    bool solve(int x, int y, int open, vector<vector<char>>& grid, int m, int n, int dx[], int dy[], vector<vector<vector<int>>> &dp){
        if(x == m-1 && y == n-1){
            if(open == 1 && grid[x][y] == ')')return true;
           
            return false;
        }
            
        if(grid[x][y] == '('){
            open++;
        }else{
            if(open == 0)return  false;
            open--;
        }
        
         if(dp[x][y][open] != -1)return dp[x][y][open];
        
        for(int i=0; i<2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && solve(nx, ny, open, grid, m, n, dx, dy, dp))return dp[x][y][open] = true;
        }
        return dp[x][y][open] = false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n  = grid[0].size();
        if((m + n - 1)&1)return false;
        int dx[] = {1, 0};
        int dy[] = {0, 1};
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(203, -1)));
        return solve(0, 0, 0, grid, m, n, dx, dy, dp);
    }
};