class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> ans(2, 0);
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < target){
                left++;
            }else if(sum > target){
                right--;
            }else{
                ans[0] = left + 1;
                ans[1] = right + 1;
                left++;
                right--;
                while(left > 0 && left < right && nums[left - 1] == nums[left])left++;
                while(right < n- 1 && left < right && nums[right+1] == nums[right])right--;
            }
        }
        return ans;
    }
};