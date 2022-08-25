class Solution {
public:
    bool canConstruct(string s, string t) {
        unordered_map<int, int> mp;
        for(int i=0; i<t.length(); i++){
            mp[t[i] - 'a']++;
        }
        
        for(int i=0; i<s.length(); i++){
            if(mp[s[i] - 'a'] <= 0){
                return false;
            }else{
                mp[s[i] - 'a']--;
            }
        }
        return true;
    }
};