class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> arr;
        for(int i=0; i<n; i++){
            if(s[i] == '|'){
                arr.push_back(i);
            }
        }
        vector<int> ans;
        for(auto it : queries){
            int low = it[0];
            int high = it[1];
            int l_ind = lower_bound(arr.begin(), arr.end(), low) - arr.begin();
            int h_ind = upper_bound(arr.begin(), arr.end(), high) - arr.begin();
            h_ind--;
            if(l_ind >= h_ind) ans.push_back(0);
            else
            ans.push_back(arr[h_ind] - arr[l_ind] - (h_ind - l_ind));
        }
        return ans;
    }
};