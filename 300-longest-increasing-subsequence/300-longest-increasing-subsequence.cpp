class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
       vector<int> ans;
        ans.push_back(arr[0]);
        int size = 1;
        for(int i=1; i<n; i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
                size++;
            }else{
                int ind = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[ind] = arr[i];
            }
        }
        return size;
    }
};