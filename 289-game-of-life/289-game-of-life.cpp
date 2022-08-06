class Solution {
    private:
    int get_live(int x, int y, int dx[], int dy[], vector<vector<int>> &board, int m, int n){
        int count = 0;
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
            if(board[nx][ny] == 1 || board[nx][ny] == 3){
                count++;
            }
        }  
        return count;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count = get_live(i, j, dx, dy, board, m, n);
                if(board[i][j] == 1){
                    if(count < 2 || count > 3){
                        board[i][j] = 3;
                    }
                }else{
                    if(count == 3){
                        board[i][j] = 2;
                    }
                }
                
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                else if(board[i][j] == 3){
                 board[i][j] = 0;   
                }
            }
        }
    }
};