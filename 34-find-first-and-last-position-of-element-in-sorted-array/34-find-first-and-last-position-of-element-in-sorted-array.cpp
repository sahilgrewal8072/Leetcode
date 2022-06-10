class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)return {-1, -1};
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(start >= n || start < n && nums[start] != target)return {-1, -1};
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {start, end-1};
    }
};