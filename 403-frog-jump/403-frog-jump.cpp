class Solution {
public:
    
    bool solve(int ind, int jump, vector<int> &stones, int n, unordered_map<int, int> &mp, vector<vector<int>> &dp){
        if(mp.find(stones[ind] + jump) == mp.end() || jump <= 0)return false;
        if(dp[ind][jump] != -1)return dp[ind][jump];
        ind = mp[stones[ind] + jump];
        if(ind == n-1)return true;
        bool low_jump = solve(ind, jump - 1, stones, n, mp, dp);
        bool mid_jump = solve(ind , jump, stones, n, mp, dp);
        bool high_jump = solve(ind, jump+1, stones, n, mp, dp);
        return dp[ind][jump] = (low_jump || mid_jump || high_jump);
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, 1, stones, n, mp, dp);
    }
};