class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> prefixSum(2e5 + 1, 0);
        int n = 2e5 + 1;
        for(int i=0; i<fruits.size(); i++){
            prefixSum[fruits[i][0]] = fruits[i][1];
        }
        
        for(int i=1; i<n; i++){
            prefixSum[i] += prefixSum[i-1]; 
        }
        
        int maxi = 0;
        int sum = 0;
        // calculation for the right
        for(int i = startPos; i<min(n-1, startPos + k); i++){
            int r = i;
            int x = i - startPos;
            int l = startPos - (k - 2*x);
            l = min(startPos, l);
            sum = prefixSum[r];
            if(l > 0){
                sum -= prefixSum[l-1];
            }
            maxi = max(maxi, sum);
        }
        
        
        // calculation for the left
        sum = 0;
        for(int i = startPos; i>=max(0, startPos - k); i--){
            int l = i;
            int x = startPos - i;
            int r = startPos + (k - 2*x);
            r = max(startPos, min(r, n-1));
            sum = prefixSum[r];
            if(l > 0){
                sum -= prefixSum[l-1];
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};