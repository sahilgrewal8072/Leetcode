    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
const int M = 1e9 + 7;
class Solution {
    private: 
    int solve(int x, int y, int m, int n, int moves, vector<vector<vector<int>>> &dp){
        if(x < 0 || y < 0 || x >= m || y >= n)return 1;
        if(moves == 0){
            return 0;
        }
        if(dp[x][y][moves] != -1)return dp[x][y][moves];
        int ans = 0;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            ans += solve(nx, ny, m, n, moves - 1, dp)%M;
            ans %= M;
        }
        return dp[x][y][moves] = ans%M; 
    }
    
    bool isOut(int x, int y, int m, int n){
        return (x < 0 || y < 0 || x >= m || y >= n);
    }
public:
    int findPaths(int m, int n, int maxMove, int r, int c) {
        int count = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(maxMove + 1, 0)));
        // return solve(r, c, m, n, maxMove, dp);
        for(int moves=1; moves <= maxMove; moves++){
            for(int x = 0; x < m; x++){
                for(int y = 0; y < n; y++){
                    for(int dir = 0; dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(isOut(nx, ny, m, n)){
                            dp[x][y][moves] += 1;
                            dp[x][y][moves] %= M;
                        }else{
                            dp[x][y][moves] += (dp[nx][ny][moves-1])%M;
                            dp[x][y][moves] %= M;
                        }
                    }
                }
            }
        }
        return dp[r][c][maxMove];
    }
};