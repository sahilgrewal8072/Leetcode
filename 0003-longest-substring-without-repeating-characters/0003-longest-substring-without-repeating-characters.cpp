class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0 || n == 1)return n;
        unordered_map<char, int> mp;
        int left = 0;
        int right = 0;
        int mx = 0;
        while(right < n){
            mp[s[right]]++;
             while(left < right && mp[s[right]] == 2){
                   mp[s[left]]--;
                   left++;
               }
           
            mx = max(mx, right - left + 1);
            right++;
        }
        return mx;
    }
};