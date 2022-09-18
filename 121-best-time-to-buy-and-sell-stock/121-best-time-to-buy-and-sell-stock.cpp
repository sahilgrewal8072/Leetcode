class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = prices[n-1];
        int mn = prices[n-1];
        int profit = 0;
        for(int i = n-2; i>= 0; i--){
            mn = prices[i];
            profit = max(profit, mx - mn);
            mx = max(mx, prices[i]);
        }
        return profit;
    }
};