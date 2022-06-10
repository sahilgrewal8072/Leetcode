class Solution {
public:
    
    int solve(int ind, int chance, vector<vector<int>> &events, int n, vector<vector<int>> &dp){
        if(ind == n || chance <= 0){
            return 0;
        }
        
        if(dp[ind][chance] != -1)return dp[ind][chance];
        int notake = solve(ind+1, chance, events, n, dp);
        int nxt_ind = n;
        int take = 0;
        int low = ind;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(events[mid][0] > events[ind][1]){
                nxt_ind = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }    
        }

         take = events[ind][2]  +  solve(nxt_ind, chance-1, events, n, dp);
        return dp[ind][chance] = max(notake, take);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        int profit = 0;
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        int chance = 2;
        return solve(0, chance, events, n, dp);
    }
};