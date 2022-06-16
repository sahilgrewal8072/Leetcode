class Solution {
public:
    
    long long ncr(int n, int r){
        long long ans = 1;
        for(int i=0; i<r; i++){
            ans *= n - i;
            ans /= i + 1;
        }
        return ans;
    }
    
    int numTrees(int n) {
        if(n <= 1)return 1;
        return ncr(2*n, n)/ (n + 1);
    }
};