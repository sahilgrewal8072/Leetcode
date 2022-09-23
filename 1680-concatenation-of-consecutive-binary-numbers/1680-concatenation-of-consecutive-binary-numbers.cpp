class Solution {
public:
    int concatenatedBinary(int n) {
        int len = 0;
        const int mod = 1e9 + 7;
        long long ans = 0;
        for(int i=1; i<=n; i++){
            if(__builtin_popcount(i) == 1)len++;
            ans = ((ans << len)%mod  + i)%mod;
        }
        return ans;
    }
};