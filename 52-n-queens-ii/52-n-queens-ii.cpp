class Solution {
    private:
        bool isPossible(vector<vector<int>> &board, int &x, int &y, int &n){
            int i=x, j=y;
            for(; i>=0 && j>=0; i--, j--){
                if(board[i][j] == 1)return false;
            }
            
            i = x, j = y;
            for(; i>=0 && j < n; i--, j++){
                if(board[i][j] == 1)return false;
            }
            
            j = y;
            i = x;
            for(; i>=0; i--){
                if(board[i][y] == 1)return false;
            }
            return true;
        }
    
    private:
    void solve(int ind, int &count, vector<vector<int>> &board, int &n){
        if(ind == n){
            count++;
            return;
        }
          
        for(int j=0; j<n; j++){
            if(isPossible(board, ind, j, n)){
                board[ind][j] = 1;
                solve(ind + 1, count, board, n);
                board[ind][j] = 0;
            }
        }
        return;
    }
    
    
public:
    int totalNQueens(int n) {        
        int count = 0;
        vector<vector<int>> board(n, vector<int> (n, 0));
        solve(0, count, board, n);
        return count;
    }
};