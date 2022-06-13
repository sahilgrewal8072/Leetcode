class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int m = items.size();
        vector<int> arr(m, 0);
        
        int prev = items[0][1];
        arr[0] = prev;
        for(int i=1; i<m; i++){
            arr[i] = max(prev, items[i][1]);
            prev = max(prev, items[i][1]);
        }
        
        int n = queries.size();
        
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            vector<int> c = {queries[i], INT_MAX};
             int ind = upper_bound(items.begin(), items.end(), c) - items.begin();
            if(ind == 0){
                ans[i] = 0;
            }else{
                ans[i] = arr[ind-1];
            }
        }
        
           for(auto it : items){
               cout<<"["<<it[0]<<","<<it[1]<<"]";
           }
        
        return ans;
    }
};