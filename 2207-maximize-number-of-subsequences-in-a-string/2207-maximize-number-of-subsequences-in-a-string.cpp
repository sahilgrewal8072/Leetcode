class Solution {
public:
    long long maximumSubsequenceCount(string s, string pattern) {
        int n = s.length();
        int count_a = 0;
        int count_b = 0;
        long long ans = 0;
        if(pattern[0] == pattern[1]){
            // long long ans = 0;
            for(int i=0; i<n; i++){
                if(s[i] == pattern[0])ans++;
            }
            return ans = (ans)*(ans + 1)/2;
        }
        
        for(int i=0; i<n; i++){
            if(s[i] == pattern[1]){
                ans += count_a;
                count_b += 1;
            }
            
            if(s[i] == pattern[0])
                count_a += 1;
            
        }
        return max(ans + count_a, ans + count_b);
    }
};