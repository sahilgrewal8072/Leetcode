class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)return vector<vector<string>>();

        unordered_map<string, vector<string>> mp;
        vector<int> count(26, 0);
        vector<int> reset(26, 0);
        for(int i = 0; i < n; i++){
            string s = strs[i];
            count = reset;
            for(int j = 0; j < s.length(); j++){
                count[s[j] - 'a']++;
            }
            string key = "";
            for(int i= 0; i < 26; i++){
                key += "#";
                key += to_string(count[i]);
            }

            if(mp.find(key) == mp.end())mp[key] = vector<string>();
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};