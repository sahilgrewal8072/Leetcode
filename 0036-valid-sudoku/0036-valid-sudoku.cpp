class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int box[9] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int val = board[i][j] - '0';
                // we will do the operations here
                if(row[i] & (1 << val)){
                    return false;
                }
                row[i] = row[i] | (1 << val);

                if(col[j] & (1 << val)){
                    return false;
                }
                col[j] |= (1 << val);

                int b = (i/3)*3 + j/3;
                if(box[b] & (1 << val)){
                    return false;
                }
                box[b] |= (1 << val);
            }
        }
        return true;
    }
};