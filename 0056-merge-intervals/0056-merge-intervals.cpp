class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        vector<int> last = intervals[0];
        for(int i = 1; i<n; i++){
            int curr_first = intervals[i][0];
            int last_last = last[1];
            if(curr_first <= last_last){
                int x =  max(intervals[i][1], last_last);
                ans.pop_back();
                last[1] = x;
                ans.push_back(last);
            }else{
                ans.push_back(intervals[i]);
                last = intervals[i];
            }

        }

        return ans;
    }
};