class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        int i = 0;
        for(i=0; i<=n; i++){
            if(!(i&1)){
                ans[i] = ans[i/2];
            }else{
                ans[i] = 1 + ans[i/2];
            }
        }
        return ans;
    }
};