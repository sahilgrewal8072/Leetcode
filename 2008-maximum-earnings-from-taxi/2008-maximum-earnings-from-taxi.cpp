class Solution {
public:
    
    long long solve(int ind, int last, vector<vector<int>> &rides, int limit, vector<long long> &dp, int n){
        if(ind == n)return 0;
        if(dp[ind] != -1)return dp[ind];
        long long notake = solve(ind + 1, last, rides, limit, dp, n);
        long long take = 0;
        long long low = ind;
        long long high = n-1;
        long long nxt_ind = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(rides[mid][0] >= rides[ind][1]){
                nxt_ind = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        take = (rides[ind][1] - rides[ind][0] + rides[ind][2]) + solve(nxt_ind, rides[ind][1], rides, limit, dp, n);
        return dp[ind] = max(take, notake);
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        int ni = rides.size();
        vector<long long> dp(ni+1, -1);
        return solve(0, 0, rides, n, dp, ni);
    }
};