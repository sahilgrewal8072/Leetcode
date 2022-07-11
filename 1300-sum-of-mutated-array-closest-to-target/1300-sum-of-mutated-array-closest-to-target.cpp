class Solution {
    private:
    int getSum(int &mid, vector<int> &arr, int &n){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += (arr[i] > mid) ? mid : arr[i];
        }
        return sum;
    }
    
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = 0;
        for(auto &it : arr){
            high = max(high, it);
        }
        int ans = INT_MAX;
        int mn_diff = INT_MAX;
        while(low <= high){
            int mid = low  + (high - low)/2;
            int curr_sum = getSum(mid, arr, n);
            if(abs(target - curr_sum) < mn_diff){
                ans = mid;
                mn_diff = abs(target - curr_sum);
            }else if(abs(target - curr_sum) == mn_diff){
                ans = min(ans, mid);
            }
            
            if(curr_sum >= target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            
            
        }
        return ans;
    }
};