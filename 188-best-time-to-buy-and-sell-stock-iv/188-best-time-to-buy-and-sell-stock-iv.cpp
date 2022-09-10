class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> nxt(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        // return solve(0, 1, 2, prices, dp, n);
    
        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy <=1; buy++){
                for(int trans = k; trans > 0; trans--){
                    if(buy){
                        curr[buy][trans] = max(-prices[ind] + nxt[0][trans], nxt[1][trans]);
                    }else
                        curr[buy][trans] = max(prices[ind] + nxt[1][trans-1], nxt[0][trans]);
                }
           } 
            nxt = curr;
        }
        return nxt[1][k];
    }
};