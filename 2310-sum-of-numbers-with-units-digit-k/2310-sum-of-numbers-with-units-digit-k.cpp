class Solution {
    private:
    int solve(int curr_num, int num, int k, vector<int> &dp){
        if(curr_num > num)return 1e8;
        if(curr_num == num)return 0;
        if(dp[curr_num] != -1)return dp[curr_num];
        int take = 1e8;
        for(int i = k; i<=num; i += 10){
            take =  min(take, 1 + solve(curr_num + i, num, k, dp));
        }
        return dp[curr_num] = take;
    }
    
public:
    int minimumNumbers(int num, int k) {
        vector<int> dp(num + 1, -1); 
        if(num == 0 || (k == 0 && num == 0))return 0;
         if(k == 0)k = 10;
        int x = solve(0, num, k, dp);
        if(x == 1e8)return -1;
        return x;
    }
};