class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(int i=0; i<t.length(); i++){
            mp[t[i]]++;
        }
        
        int l = 0;
        int r = 0;
        int match_count = 0;
        int mn_len = INT_MAX;
        int start = 0;
        while(r < s.length()){
           if(mp[s[r]] > 0){
               match_count++;
           }
            mp[s[r]]--;
            r++;
            while(match_count == t.length()){
                if(r-l  < mn_len){
                    start = l;
                    mn_len = r - l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    match_count--;
                }
                l++;
            }
                
            }
        if(mn_len != INT_MAX)
        return s.substr(start, mn_len);
        return "";
        }
    
};