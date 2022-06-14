class Solution {
public:
    int minimumBuckets(string s) {
        // Dry run on cases : .HH. and H.H
        int n = s.length();
        int ans = 0;
        for(int i=0; i < n ;){
            if(s[i] == 'H'){
                if(i + 1 < n && s[i+1] == '.'){
                ans ++;
                i += 3;
                continue;
            }
                
                if(i - 1 >= 0 && s[i-1] == '.'){
                    ans ++;
                }else{
                    return -1;
                }
            }
            i++;
        }
        return ans;
    }
};