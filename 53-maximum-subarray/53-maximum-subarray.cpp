class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n = nums.size();
        int mx = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++){
            sum = max(nums[i], nums[i] + sum);
            mx = max(mx, sum);
        }
        return mx;
    }
};