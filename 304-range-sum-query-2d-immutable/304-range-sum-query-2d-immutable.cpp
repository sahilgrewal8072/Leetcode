class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
          dp.resize(n, vector<int>(m));
            for(int i=0; i<n; i++){
             dp[i][0] = matrix[i][0];
            for(int j=1; j<m; j++){
                dp[i][j] = dp[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int row_start = col1;
        int row_end = col2;
        int col_start = row1;
        int col_end = row2;
        long long int sum = 0;
        for(int r = row1; r <= row2; r++){
            if(col1 - 1 < 0 )sum += dp[r][col2];
            else{
                sum += dp[r][col2] - dp[r][col1-1];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */