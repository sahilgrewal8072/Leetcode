class Solution {
    private:
    bool isPossible(int &sum, int m, vector<int> &nums, int &n){
        int curr_sum = 0;
        int sub = 1;
        for(int i=0; i<n; i++){
            if(curr_sum + nums[i] <= sum){
                curr_sum += nums[i];
            }else{
                sub++;
                curr_sum = nums[i];
            }
        }
        if(sub <= m)return true;
        return false;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int large = INT_MIN;
        for(auto &it : nums){
            sum += it;
            large = max(large, it);
        }
        int n = nums.size();
        int low = large;
        int high = sum;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, m, nums, n)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};