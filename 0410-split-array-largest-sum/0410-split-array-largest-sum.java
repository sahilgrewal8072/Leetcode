class Solution {
    public static int satisfy(int[] nums, int mid, int k, int n){
        int curr_sum = 0;
        int splits = 1;
        for(int i=0; i<n; i++){
            if(curr_sum + nums[i] > mid){
                splits++;
                curr_sum = nums[i];
            }else{
                curr_sum += nums[i];
            }
        }
        return splits;
    }
    
    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        int low = -1;
        int high = 0;
        for(int i=0; i<n; i++){
            high += nums[i];
            low = Math.max(low, nums[i]);
        }
        
        int mid;
        int ans = -1;
        while(low <= high){
            mid = (low + high)/2;
            if(satisfy(nums, mid, k, n) > k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
    
}