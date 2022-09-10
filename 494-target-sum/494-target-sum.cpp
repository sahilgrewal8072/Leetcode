class Solution {
public:
    
    
    int solve(int n, vector<int> &nums, int target){
        if(n == 0){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        
        return (solve(n-1, nums, target - nums[n-1]) + solve(n-1, nums, target + nums[n-1]));
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
       return solve(n, nums, target);
    }
};