class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(n != t.length())return false;
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for(int i=0; i<n; i++){
            hash1[s[i] - 'a']++;
            hash2[t[i] - 'a']++;
        }
        
        return hash1 == hash2;
    }
};