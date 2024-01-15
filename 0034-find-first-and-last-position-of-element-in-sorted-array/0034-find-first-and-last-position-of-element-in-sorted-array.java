class Solution {
    
    public static int lower_bond(int[] arr, int target, int n){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        if(ans != n && arr[ans] != target)return -1;
        if(ans == n)return -1;
        return ans;
    }
    
    public static int upper_bond(int[] arr, int target, int n){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] <= target){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
                if(ans != n && arr[ans] != target)return -1;
        if(ans == n)return -1;
        return ans;
    }
    
    public int[] searchRange(int[] arr, int target) {
        int n = arr.length;
        int[] ans = new int[2];
        ans[0] = lower_bond(arr, target, n);
        ans[1] = upper_bond(arr, target, n);
        return ans;
    }
}