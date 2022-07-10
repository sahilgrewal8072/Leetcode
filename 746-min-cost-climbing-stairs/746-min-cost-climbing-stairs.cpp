class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0);
        int nxt = 0;
        int n_nxt = 0;
        int curr;
        for(int i=n-1; i>=0; i--){
            curr = cost[i] + min(n_nxt, nxt);
            n_nxt = nxt;
            nxt = curr;
        }
        return min(nxt, n_nxt);
    }
};