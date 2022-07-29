class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        int m = words[0].length();
        int n = words.size();
        for(int i=0; i<n; i++){
            string curr = words[i];
            bool flag = true;
            for(int j=0; j<m; j++){
                if(mp2.find(pattern[j]) != mp2.end() && mp2[pattern[j]] != curr[j] || mp.find(curr[j]) != mp.end() && mp[curr[j]] != pattern[j]){
                    flag = false;
                    break;
                }else{
                    mp2[pattern[j]] = curr[j];
                     mp[curr[j]] = pattern[j];
                }
            }
            mp.clear();
            mp2.clear();
            if(flag){
                ans.push_back(curr);
            }
        }
        return ans;
    }
};