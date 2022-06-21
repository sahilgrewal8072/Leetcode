class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long sum = 0;
        int len = 0;
        int fact = 0;
        int i =  0;
        for(i = n-1; i>=0; i--){
            if(s[i] == '1'){
                if(sum + pow(2, n - i - 1)*1 > k)break;
                sum += pow(2, n - i - 1)*1;
            }
            len++;
        }
        
        for(i; i>=0; i--){
            if(s[i] == '0')len++;
        }
        return len;
    }
};