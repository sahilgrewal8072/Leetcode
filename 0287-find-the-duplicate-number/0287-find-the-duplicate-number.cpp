class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(nums[i] > 0){
            nums[i] = -1*nums[i];
            i = -1*nums[i];
        }
        return i;
    }
};