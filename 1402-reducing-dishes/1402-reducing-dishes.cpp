class Solution {
public:
    int solve(int ind, int time, vector<int> &arr, vector<vector<int>> &dp, int n){
        if(ind == n){
            return 0;
        }
        
        if(dp[ind][time] != -1)return dp[ind][time];
        int take =  arr[ind]*time + solve(ind + 1, time + 1, arr, dp, n);
        int notake = solve(ind + 1, time, arr, dp, n);
        return dp[ind][time] = max(take, notake);
    }
    
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
    vector<vector<int>> dp(n+1, vector<int>(n+2, 0));
        // return solve(0, 1, arr, dp, n);
        for(int ind=n-1; ind>=0; ind--){
            for(int time = n ; time>=1; time--){
                 int take =  arr[ind]*time + dp[ind + 1][time + 1];
                int notake = dp[ind + 1][time];
                dp[ind][time] = max(take, notake);
            }
        }
        return dp[0][1];
    }
};