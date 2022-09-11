class Solution {
    private:
    int overall = 0;
    int solve(int ind1, int ind2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        if(ind1 == 0 || ind2 == 0)return 0;
        int ans = 0;
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(nums1[ind1-1] == nums2[ind2-1]){
            ans = max(1 + solve(ind1-1, ind2-1, nums1, nums2, dp), 0);
        }
        overall = max(overall, ans);
        solve(ind1-1, ind2, nums1, nums2, dp);
        solve(ind1, ind2-1, nums1, nums2, dp);
        return dp[ind1][ind2] = ans;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // solve(m, n, nums1, nums2, dp);
        // return overall;
        int ans = 0;
        vector<int> prev(n + 1, 0);
       
        for(int ind1 = 1; ind1 <= m; ind1++){
             vector<int> curr(n + 1, 0);
            for(int ind2 = 1; ind2 <= n; ind2++){
                if(nums1[ind1-1] == nums2[ind2-1]){
                    curr[ind2] = max(1 + prev[ind2-1], 0);
                }
                ans = max(ans, curr[ind2]);
            }
            prev = curr;
        }
        return ans;
    }
};