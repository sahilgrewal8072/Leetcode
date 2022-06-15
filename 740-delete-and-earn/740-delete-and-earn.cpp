class Solution {
public:
    int solve(int ind, vector<int> &nums, int n, unordered_map<int, int> &mp, vector<int> &dp){
        if(ind >= n)return 0;
        if(dp[ind] != -1)return dp[ind];
        int take = 0;
        if(ind + 1 < n && nums[ind+1]  == nums[ind] + 1){
            take = mp[nums[ind]]*nums[ind] + solve(ind+2, nums, n, mp, dp);
        }else{
            take = mp[nums[ind]]*nums[ind]  + solve(ind+1, nums, n, mp, dp);
        }
        
        int notake = solve(ind + 1, nums, n, mp, dp);
        return dp[ind]  = max(take, notake);
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<int> arr;
        arr.push_back(nums[0]);
        int prev = 0;
        for(int i=1; i<n; i++){
            if(arr[prev] == nums[i])continue;
            prev++;
            arr.push_back(nums[i]);
        }
        vector<int> dp(prev+1, -1);
        // cout<<prev<<endl;
        // for(auto it : arr)cout<<it<<" ";
        return solve(0, arr, prev+1, mp, dp);
   }
};