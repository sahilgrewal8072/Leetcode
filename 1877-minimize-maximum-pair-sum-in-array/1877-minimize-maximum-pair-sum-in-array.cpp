class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = 0;
        int i=0;
        int j = n-1;
        while(i<j){
            mx = max(mx, (nums[i++] + nums[j--]));
        }
        return mx;
    }
};