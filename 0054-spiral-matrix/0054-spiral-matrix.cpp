class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start_r = 0;
        int start_c = 0;
        int end_r = m;
        int end_c = n;
        vector<int> ans;
        vector<char> dir = {'R', 'D', 'L', 'U'};
        int itr = 0;
        while((start_r < end_r) && (start_c < end_c)){
            if(dir[itr] == 'R'){
                for(int i = start_c; i < end_c; i++){
                    ans.push_back(matrix[start_r][i]);
                }
                start_r++;
            }
            
            if(dir[itr] == 'D'){
                for(int i = start_r; i < end_r; i++){
                    ans.push_back(matrix[i][end_c-1]);
                }
                end_c--;
            }
            
            if(dir[itr] == 'L'){
                for(int i = end_c-1; i >= start_c; i--){
                    ans.push_back(matrix[end_r-1][i]);
                }
                end_r--;
            }
            
            if(dir[itr] == 'U'){
                for(int i = end_r-1; i >= start_r; i--){
                    ans.push_back(matrix[i][start_c]);
                }
                start_c++;
            }
            itr++;
            itr %= 4;
        }
        return ans;
    }
};