class Solution {
    private:
    bool isPossible(int x, int y, vector<vector<int>> &board, int n){
        // check diagonal
        int _x = x;
        int _y = y;
        for(; _x >= 0 && _y >= 0; _x--, _y--){
            if(board[_x][_y] == 1)return false;
        }
        
        // check for anti-diagonal
        _x = x;
        _y = y;
        for(; _x >= 0 && _y < n; _x--, _y++){
           if(board[_x][_y] == 1)return false;
        }
        
        _x = x;
        _y = y;
        for(; _x >= 0 ; _x--){
            if(board[_x][y] == 1)return false;
        }
        
        return true;
    }
    
    private: 
    void solve(int ind, string &curr, vector<vector<int>> &board, int n, vector<vector<string>> &ans, vector<string> &moves){
        if(ind == n){
            ans.push_back(moves);
            return;
        }
        
        string x = curr;
        for(int j=0; j<n; j++){
            if(isPossible(ind, j, board, n)){
                curr[j] = 'Q';
                board[ind][j] = 1;
                moves.push_back(curr);
                solve(ind + 1, x, board, n, ans, moves);
                board[ind][j] = 0;
                curr[j] = '.';
                moves.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<string> moves;
        string curr = "";
        for(int i=0; i<n; i++){
            curr += ".";
        }
        
        solve(0, curr, board, n, ans, moves);
        return ans;
    }
};