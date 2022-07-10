class Solution {
    private:
        bool isPossible(vector<vector<int>> &board, int x, int y, int n){
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
    void solve(int ind, string &curr, vector<string> &stocks, vector<vector<int>> &board, int n, vector<vector<string>> &ans){
        if(ind == n){
            ans.push_back(stocks);
            return;
        }
        
        string x = curr;
        for(int j=0; j<n; j++){
            if(isPossible(board, ind, j, n)){
                board[ind][j] = 1;
                curr[j] = 'Q';
                stocks.push_back(curr);
                solve(ind + 1, x, stocks, board, n, ans);
                curr[j] = '.';
                board[ind][j] = 0;
                stocks.pop_back();
            }
        }
        return;
    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string curr;
        for(int i=0; i<n; i++){
            curr += '.';
        }
        
        vector<string> stocks;
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(0, curr, stocks, board, n, ans);
        return ans;
    }
};