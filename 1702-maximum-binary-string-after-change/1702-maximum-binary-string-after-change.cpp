class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.length();
        int zeros_encounter = 0;
        int ones = 0;
        int zeros = 0;
        for(int i=0; i < n; i++){
            if(s[i] == '1')zeros_encounter++;
            else
                break;   
        }
        
        string ans = "";
        for(int i = zeros_encounter; i<n; i++){
            if(s[i] == '1')ones++;
            else
                zeros++;
        }
        
        for(int i = 0; i < zeros_encounter; i++){
            ans += '1';
        }
        
        for(int i=1; i<zeros; i++){
            ans += '1';
        }
        
        if(zeros > 0){
            ans += '0';
        }
        
        for(int i=0; i<ones; i++){
            ans += '1';
        }
        return ans;
    }
};