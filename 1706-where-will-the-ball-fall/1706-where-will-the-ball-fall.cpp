class Solution {
    private:
    bool isValid(int nx, int ny, int m, int n){
        if(nx < 0 || ny < 0 || nx >= m || ny >= n)return false; 
        return true;
    }
    
public:
    
    int solve(int x, int y, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){    
        if(x == m){
            return y;
        }    
        if(dp[x][y] != -2)return dp[x][y];

        if(grid[x][y] == 1){
            if(isValid(x, y + 1, m, n) && grid[x][y+1] == 1){
                return dp[x][y] = solve(x+1, y+1, grid, m, n, dp);
            }
        }else{
            if(isValid(x, y-1, m, n) && grid[x][y-1] == -1){
                return dp[x][y] = solve(x + 1, y - 1, grid, m, n, dp);
            }
        }
        return dp[x][y] = -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n, -2));
        vector<int> ans(n, -1);
        
        for(int i=0; i<n; i++){
            dp[m][i] = i; 
        }
        
        for(int x=m-1; x>=0; x--){
            for(int y = 0; y < n; y++){
                if(grid[x][y] == 1){
                if(isValid(x, y + 1, m, n) && grid[x][y+1] == 1){
                     dp[x][y] = dp[x+1][y+1];
            }else{
                    dp[x][y] = -1;
                }
        }else{
            if(isValid(x, y-1, m, n) && grid[x][y-1] == -1){
                 dp[x][y] = dp[x + 1][y - 1];
            }else{
                dp[x][y] = -1;
                }
        }
            }
        }
          for(int i=0; i<n; i++){
            ans[i] = dp[0][i];
        }      
        return ans;
    }
};