class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int last = nums[0];
        int k = 1;
        int i = 1;
        while(i < n){
            if(nums[i] != last){
                nums[k] = nums[i];
                last = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};