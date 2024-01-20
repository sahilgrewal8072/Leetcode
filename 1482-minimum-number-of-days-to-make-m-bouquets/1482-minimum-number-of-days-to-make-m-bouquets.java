class Solution {
    
    public static int mx(int[] bloomDay, int n){
        int mxi = -1;
        for(int i = 0; i<n; i++){
            mxi = Math.max(mxi, bloomDay[i]);
        }
        return mxi;
    }
    
    public static int mn(int[] bloomDay, int n){
        int mni = 10^9 + 1;
        for(int i = 0; i<n; i++){
            mni = Math.min(mni, bloomDay[i]);
        }
        return mni;
    }
    
    public boolean satisfy(int[] bloomDay, int mid, int m, int k){
        int count = 0;
        int n = bloomDay.length;
        int flowers = 0;
        for(int i = 0; i<n; i++){
            if(bloomDay[i] <= mid){
                count++;
            }else{
                flowers += (count/k);
                count = 0;
            }
        }
        
        flowers += count/k;
        if(flowers >= m){ 
        return true;
        }
        return false;
    }
    
    public int minDays(int[] bloomDay, int m, int k) {
        long value = (long)m*k;
        int n = bloomDay.length;
        if(value > n)return -1;
        int low = mn(bloomDay, n);
        int high = mx(bloomDay, n);
        int mid = 0;
        int ans = high;
        while(low <= high){
            mid = (low + high)/2;
            if(satisfy(bloomDay, mid, m, k)){
                ans = mid;
                high  = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
}