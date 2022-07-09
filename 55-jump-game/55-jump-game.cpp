class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jump_req = 0;
        for(int i=n-2; i>= 0; i--){
            jump_req++;
            if(nums[i] >= jump_req){
                jump_req = 0;
            }
        }
        return (jump_req == 0);
    }
};