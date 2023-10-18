class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int &target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i-1] == nums[i])continue;
            for(int j = i + 1; j<n; j++){
                if(j>i+1 && nums[j-1] == nums[j])continue;
                    int left = j+1;
                    int right = n-1;
                    while(left < right){
                        long long sum = nums[i];
                        sum += nums[left];
                        sum += nums[right];
                        sum += nums[j];
                        if(sum == target){
                            ans.push_back({nums[i],nums[j], nums[left], nums[right]});
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
          
        }
        return ans;
    }
};