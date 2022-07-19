class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> res(i+1, 1);
            for(int j=1; j<i; j++){
                res[j] = ans[i-1][j] + ans[i-1][j-1];
             }
            ans.push_back(res);
        }
        return ans;
    }
};