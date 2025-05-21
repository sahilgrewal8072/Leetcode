class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int hottestDay = 0;
        for(int i = n-1; i >=0; i--){
            if(nums[i] >= hottestDay){
                hottestDay = nums[i];
                continue;
            }
            int nxt_ind = i + 1;
            while(nxt_ind < n && nums[nxt_ind] <= nums[i]){
                nxt_ind += ans[nxt_ind];
            }
            ans[i] = nxt_ind - i;
        }
        return ans;
    }
};