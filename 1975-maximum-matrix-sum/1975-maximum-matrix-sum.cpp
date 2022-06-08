class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int smallest = 1e5;
        int neg_count = 0;
        long long sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0)neg_count++;
                smallest = min(smallest, abs(matrix[i][j]));
            }
        }
        if(neg_count&1)return sum - 2*abs(smallest);
        return sum;
    }
};