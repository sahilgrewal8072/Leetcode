class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, bool> mp;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')continue;
                    string num = to_string(board[i][j]);
                if(mp[num + "col" + to_string(j)] || mp[num + "row" + to_string(i)] || mp[num + "block" + to_string(i/3) + "-" + to_string(j/3)]){
                    return false;
                }
                mp[num + "col" + to_string(j)] = 1;
                mp[num + "row" + to_string(i)] = 1;
                mp[num + "block" + to_string(i/3) + "-" + to_string(j/3)] = 1;
            }
        }
        return true;
    }
};