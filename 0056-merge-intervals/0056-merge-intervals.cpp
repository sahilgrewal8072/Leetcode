class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        int curr_size = 1;
        for(int i = 1; i < n; i++){
            int ele = ans[curr_size - 1][1];
            if(ele >= intervals[i][0]){
                ans[curr_size - 1][1] = max(ele, intervals[i][1]);
            }else{
                curr_size++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};