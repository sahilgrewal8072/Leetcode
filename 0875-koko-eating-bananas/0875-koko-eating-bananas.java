class Solution {
    
    public static int find_max(int[] piles, int n){
        int mx = -1;
        for(int i=0; i<n; i++){
            mx = Math.max(piles[i], mx);
        }
        return mx;
    }
    
    public static boolean satisfy(int[] piles, int mid, int hourLimit, int n){
        int count = 0;
        for(int i = 0; i<n; i++){
            count += Math.ceil((double)piles[i]/(double)mid);
            if(count > hourLimit)return false;
        }
        return true;
    }
    
    public int minEatingSpeed(int[] piles, int hourLimit) {
        int low = 1;
        int n = piles.length;
        int high = find_max(piles, n);
        int mid = 0;
        int ans = high;
        while(low <= high){
            mid = (low + high)/2;
            if(satisfy(piles, mid, hourLimit, n)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
}