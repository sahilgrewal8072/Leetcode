class Solution {
    private:
    bool solve(string s1, string s2, unordered_map<string, bool> &mp){
        int n = s1.length();
        if(n == 1){
            return s1 == s2;
        }
        
        if(s1 == s2)return true;
        string curr = s1 + "*" + s2;
        if(mp.find(curr) != mp.end())return mp[curr];
        for(int i=1; i<n; i++){
            bool swapped = (solve(s1.substr(0, i), s2.substr(n-i, i), mp) && solve(s1.substr(i, n-i), s2.substr(0, n-i), mp));
            bool notswapped = (solve(s1.substr(0, i), s2.substr(0, i), mp) && solve(s1.substr(i, n-i), s2.substr(i, n-i), mp));
            if(swapped or notswapped)return mp[curr] = true;
        }
        return mp[curr] = false;
    }
    
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        unordered_map<string, bool> dp;
        if(n != m)return false;
        return solve(s1, s2, dp);
    }
};