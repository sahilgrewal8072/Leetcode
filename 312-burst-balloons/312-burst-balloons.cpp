class Solution {
public:
    
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j)return 0;
        // int cost = INT_MIN;
        if(dp[i][j] != -1)return dp[i][j];
        int mx = INT_MIN;
        for(int ind=i; ind<=j; ind++){
           int cost = (nums[i-1]*nums[j+1]*nums[ind]) + solve(i,ind-1, nums, dp) + solve(ind+1, j, nums, dp);
            mx = max(cost, mx);
        }
        return dp[i][j] = mx;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, nums, dp);
    }
};