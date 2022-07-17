class Solution {
    private:
    int findKthsmallest(vector<string>& nums, int k, int n) {
        priority_queue<pair<string, int>> pq;
        for(int i=0; i<n; i++){
            // int x = stoi(nums[i]);
            // cout<<x<<" ";
             pq.push({nums[i], i});
            if(pq.size() > k)pq.pop();        
        }
        // cout<<endl;
        return pq.top().second;
    }

    
public:
    static bool cmp(vector<int> &a,  vector<int> &b){
        return a[1] > b[1];
    }
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // sort(queries.begin(), queries.end(), cmp);
        int n = queries.size();
        int m = nums.size();
        int len = nums[0].length();
        vector<int> ans(n);
        vector<string> nums1(m);
        for(int i=0; i<n; i++){
            for(int j = 0; j < m; j++){
                // if(len - queries[i][1] <= 0)continue;
                nums1[j] = nums[j].substr(len - queries[i][1], len);
            }
            // for(auto it : nums1)cout<<it<<" ";
            // cout<<endl;
            ans[i] = findKthsmallest(nums1, queries[i][0], m);
        }
        return ans;
    }
};