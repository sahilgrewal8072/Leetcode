class Solution {
public:
   
    
    int maxEnvelopes(vector<vector<int>>& arr) {
         int n = arr.size();
        if(n == 0)return 0;
       vector<int> dp;  
        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b){
             return ((a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]));
        });
        dp.push_back(arr[0][1]);
        int size = 1;
        for(int i=1; i<n; i++){
            int ind = lower_bound(dp.begin(), dp.end(), arr[i][1]) - dp.begin();
            if(ind >= size){
                dp.push_back(arr[i][1]);
                size++;
            }else{
                dp[ind] = arr[i][1];
            }
        }
        return size;
    }
};