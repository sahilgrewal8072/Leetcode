class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int mx = 0;
        vector<int> mp(26, 0);
        int maxFreqElement = 0;
        int left = 0;
        for(int right = 0; right < n; right++){
            mp[s[right] - 'A']++;
             maxFreqElement = max(maxFreqElement, mp[s[right] - 'A']);
                int curr_len = right - left + 1;
            if(curr_len - maxFreqElement > k){
                mp[s[left] - 'A']--;
                left++;
            }
            mx = max(mx, right - left + 1);
        }
        return mx;
    }
};