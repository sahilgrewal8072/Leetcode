class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n =  nums.length;
        int curr_len = 0;
        int mx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                curr_len++;
                mx = Math.max(curr_len, mx);
            }else{
                curr_len = 0;
            }
        }
        return mx;
    }
}