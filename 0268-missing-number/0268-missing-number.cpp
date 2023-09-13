class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int end = false;
        for(int i=0; i<n; i++){
            if(abs(nums[i]) == n){
                end = true;
                continue;
            }
            nums[abs(nums[i])] = -1*nums[abs(nums[i])];
        }
        int alt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0)alt = i;
            if(nums[i] > 0)return i;
        }
        if(end) return alt;
        return n;
    }
};