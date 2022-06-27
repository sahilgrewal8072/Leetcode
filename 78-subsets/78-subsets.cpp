class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets_count = (1 << n) - 1;
        vector<vector<int>> ans;
        for(int mask=0; mask<=subsets_count; mask++){
            vector<int> sub;
            for(int j = 0; j<n; j++){
                if(mask & (1 << j)){
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};