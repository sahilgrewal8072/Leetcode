class Solution {
public:
    // Must Revise
    int solve(int k, int f, vector<vector<int>> &dp){
        if(f == 0 || f == 1){
            return f;
        }
        
        if(k == 1){
            return f;
        }
        
        if(dp[k][f] != -1)return dp[k][f];
        
        int low = 1;
        int high = f;
        int mn = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            int left = solve(k-1, mid-1, dp);
            int right = solve(k, f-mid, dp);
            int temp = 1 + max(left, right);
            
            // look for worst always
            if(left > right){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            mn = min(mn, temp);
        }
        
        return dp[k][f] = mn;
    }
    
    int twoEggDrop(int n) {
        vector<vector<int>> dp(2 + 1, vector<int> (n + 1, -1));
        return solve(2, n, dp);
    }
};