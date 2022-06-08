class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int curr_cost = 0;
        int mx = 0;
        int left = 0;
        for(int right = 0; right<n; right++){
            curr_cost += abs((s[right] - 'a') - (t[right] - 'a'));
            if(curr_cost > maxCost){
                curr_cost -= abs((s[left] - 'a') - (t[left] - 'a'));
                left++;
            }
            mx = max(mx, right - left + 1);
        }
        return mx;
    }
};