class Solution {
public:
    
    void dfs(int x, int y, vector<vector<char>> &board, int dx[], int dy[], int m, int n){
        board[x][y] = '#';
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > 0 && ny > 0 && nx < m-1 && ny < n-1 && board[nx][ny] == 'O'){    
                dfs(nx, ny, board, dx, dy, m, n);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int i=0; i<n; i++){
            if(board[0][i] == 'O')
            dfs(0, i, board, dx, dy, m, n);
            if(board[m-1][i] == 'O')
            dfs(m-1, i, board, dx, dy, m, n);
        }
        
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O')
                dfs(i, 0, board, dx, dy, m, n);
            if(board[i][n-1] == 'O')
                dfs(i, n-1, board, dx, dy, m, n);
        }
       
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};