class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
                int i=0, j=0;
    int n = arr.size();
       for(i=0; i<n; i++){
           for(j=0; j<i; j++){
               swap(arr[i][j], arr[j][i]);
           }
       }
       for(i=0; i<n; i++){
           reverse(arr[i].begin(), arr[i].end());
       }
    }
};