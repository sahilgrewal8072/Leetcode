class Solution {
public:
    int minTimeToType(string s) {
        int n = s.length();
        int ans = 0;
        char prev = 'a';
        for(int i=0; i<n; i++){
            int mn = min(abs(prev - s[i]), min(abs(s[i] - 'a' + 'z' - prev + 1), abs(prev - 'a' + 'z' - s[i] + 1)));
            ans += (mn + 1);
            prev = s[i];
        }
        return ans;
    }
};