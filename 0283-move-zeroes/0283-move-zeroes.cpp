class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int pointer = -1;
        for(int i = 0; i < n; i++){
            if(pointer + 1 < n && nums[i] != 0){
                nums[++pointer] = nums[i];
            }
        }
        
        while(pointer+1 < n){
            nums[++pointer] = 0;
        }
        
    }
};