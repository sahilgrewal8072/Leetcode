class Solution {
    private:
    int solve(int start, int end, int multi, vector<int> &nums, vector<int> &multipliers, int n, int m, vector<vector<int>> &dp){
        if(multi >= m || start > end){
            return 0;
        }
        
        if(start == end)
        {
            return multipliers[multi]*nums[start];
        }
        
        if(dp[start][multi] != -1001)return dp[start][multi];
        
        // take front ele
        int front = multipliers[multi]*nums[start] + solve(start + 1, end, multi+1, nums, multipliers, n, m, dp);
        int back = multipliers[multi]*nums[end]  + solve(start, end - 1, multi+1, nums, multipliers, n, m, dp);
        return dp[start][multi] = max(front, back);
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m , vector<int> (m, -1001));
        int mx = 0;
        return solve(0, n-1, 0, nums, multipliers, n, m, dp);
        // for(int start = 0, end = n-1; start <= end; start++, end--){
        //         for(int multi = 0; multi <= m-1; multi++){
        //             if(start > end)continue;
        //             if(start == end){
        //                 dp[start][end] = multipliers[multi]*nums[start];
        //             }else{
        //                 int front = multipliers[multi]*nums[start] + dp[start + 1][end];
        //                 int back = multipliers[multi]*nums[end] + dp[start][end-1];
        //                 dp[start][end] = max(front, back);
        //             }
        //         } 
        //         mx = max(mx, dp[start][end]);
        //     }
        // for(auto it : dp){
        //     for(auto pt : it){
        //         cout<<pt<<" ";
        //     }
        //     cout<<endl;
        // }
        // return dp[0][0];
    }
};