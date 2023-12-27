class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int mx = -100000;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            mx = Math.max(sum, mx);
            if(sum < 0){
                sum = 0;
            }
        }
        return mx;
    }
}