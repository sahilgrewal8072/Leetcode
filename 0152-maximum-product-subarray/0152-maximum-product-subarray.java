class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        long prefix = 1;
        long suffix = 1;
        long mx = -11;
        for(int i = 0; i<n; i++){
            if(prefix == 0)prefix = 1;
            if(suffix == 0)suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            mx = Math.max(mx, Math.max(prefix, suffix));
        }
        return (int)mx;
    }
}