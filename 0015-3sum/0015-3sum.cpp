class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i-1] == nums[i])continue;
            int left = i+1;
            int right = n-1;
            while(left < right){
                long long sum = nums[i];
                sum += nums[left];
                sum += nums[right];
                if(sum == target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                     while(left < right && nums[left] == nums[left-1])left++;
                    while(left < right && nums[right] == nums[right+1])right--;

                }else if(sum < target){
                    left++;
                }else if(sum > target){
                    right--;
                }

            }
        }
        return ans;
    }
};