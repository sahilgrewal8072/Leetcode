class Solution {
    public static int mx(int[] nums, int n){
        int mxi = -1;
        for(int i = 0; i<n; i++){
            mxi = Math.max(mxi, nums[i]);
        }
        return mxi;
    }
    
    public static boolean satisfy(int[] nums, int mid, int threshold, int n){
        int sum = 0;
        int div = mid;
        for(int i = 0; i<n; i++){
            sum += Math.ceil((double)nums[i]/(double)div);
            if(sum > threshold)return false;
        }
        return true;
    }
    
    
    public int smallestDivisor(int[] nums, int threshold) {
        int n = nums.length;
        int low = 1;
        int high = mx(nums, n);
        int mid = 0;
        int ans = high;
        while(low <= high){
            mid = (low + high)/2;
            if(satisfy(nums, mid, threshold, n)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
}