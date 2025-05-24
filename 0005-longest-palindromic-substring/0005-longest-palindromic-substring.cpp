class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int curr_l = 0;
        int curr_r = 0;
        int mx = 0;
        for(int center = 0; center < n; center++){
            //case 1: consider odd length palindrome
            int l = center, r = center;
            while(l >= 0 && r < n && s[l] == s[r]){
                int len = r - l + 1;
                if(len > mx){
                    curr_l = l;
                    curr_r = r;
                    mx = len;
                }
                l--;
                r++;
            }
            //case 2 : consider the even length palindrome
            l = center, r = center + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                int len = r - l + 1;
                if(len > mx){
                    curr_l = l;
                    curr_r = r;
                    mx = len;
                }
                l--;
                r++;
            }
        }
        cout<<curr_r<<" ";
        return s.substr(curr_l, mx);
    }
};