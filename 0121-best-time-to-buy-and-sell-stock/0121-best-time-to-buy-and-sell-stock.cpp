class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int profit = 0;
        int curr_deal = 0;
        int mini = arr[0];
        for(int i = 1; i<n; i++){
            curr_deal = arr[i] - mini;
            profit = max(profit, curr_deal);
            mini = min(mini, arr[i]);
        }
        return profit;
    }
};