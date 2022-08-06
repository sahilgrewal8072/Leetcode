class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)return 1;
        vector<int> dp(n, 1);
        dp[1] = arr[0] != arr[1] ?  2 :  1;
        int mx = dp[1];
        for(int i=2; i<n; i++){
            if(arr[i-2] > arr[i-1] && arr[i-1] < arr[i] || arr[i-2] < arr[i-1] && arr[i] < arr[i-1]){
                dp[i] = 1 + dp[i-1];
            }else{
                dp[i] = arr[i] != arr[i-1] ?  2 :  1;
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};