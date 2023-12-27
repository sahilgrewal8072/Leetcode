class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int curr_deal = 0;
        int profit_mx = 0;
        int min_buy = prices[0];
        for(int i = 1; i<n; i++){
            curr_deal = prices[i] - min_buy;
            profit_mx = Math.max(profit_mx, curr_deal);
            min_buy = Math.min(min_buy, prices[i]);
        }
        return profit_mx;
    }
}