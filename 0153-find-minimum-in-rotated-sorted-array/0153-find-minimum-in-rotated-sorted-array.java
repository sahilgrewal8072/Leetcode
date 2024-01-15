class Solution {
    public static int find_pivot(int[] nums, int n){
        int low = 0;
        int high = n-1;
        int pivot = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(mid-1 >= 0 && nums[mid-1] > nums[mid]){
                return mid;
            }else if(nums[mid] >= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return pivot;
    }
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n == 1)return nums[0];
        int pivot = find_pivot(nums, n);
        if(pivot == -1)return nums[0];
        return nums[pivot];
    }
}