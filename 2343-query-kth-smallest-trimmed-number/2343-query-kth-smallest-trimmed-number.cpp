class Solution {
    private:
    int findKthsmallest(vector<string>& nums, int k, int n) {
        priority_queue<pair<string, int>> pq;
        for(int i=0; i<n; i++){
             pq.push({nums[i], i});
            if(pq.size() > k)pq.pop();        
        }
        return pq.top().second;
    }

    
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        int len = nums[0].length();
        vector<int> ans(n);
        vector<string> nums1(m);
        for(int i=0; i<n; i++){
            for(int j = 0; j < m; j++){
                nums1[j] = nums[j].substr(len - queries[i][1], len);
            }
            ans[i] = findKthsmallest(nums1, queries[i][0], m);
        }
        
        return ans;
    }
};