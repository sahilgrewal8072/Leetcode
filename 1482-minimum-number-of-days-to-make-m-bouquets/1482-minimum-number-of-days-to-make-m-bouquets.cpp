class Solution {
    private:
    bool isPossible(int &day, int &m, vector<int> &arr, int &k, int &n){
       int flowers = 0;
        int dup_k = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= day){
                dup_k++;
            }else if(arr[i] >= day){
                dup_k = 0;
            }
            
            if(dup_k == k){
                dup_k = 0;
                flowers++;
            }
            if(flowers == m){
                return true;
            }
        }
        return false;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(k == 0 || m == 0 || n == 0)return 0;
        if(m*k > n)return -1;
        // sort(bloomDay.begin(), bloomDay.end());
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(auto &it : bloomDay){
            mx = max(mx, it);
            mn = min(mn, it);
        }
        int low = mn;
        int ans = -1;
        int high = mx;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, m, bloomDay, k, n)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};