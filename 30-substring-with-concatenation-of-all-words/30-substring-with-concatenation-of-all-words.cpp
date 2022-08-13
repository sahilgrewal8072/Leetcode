class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int w = words.size();
        int n = s.length();
        int m = words[0].length();
        vector<int> ans;
        unordered_map<string, int> mp;
        for(auto it : words){
            mp[it]++;
        }
        
        for(int k = 0; k < m; k++){
            int left = k;
            int curr_len = 0;
            unordered_map<string, int> seen;
            for(int i = left; i + m <= n; i += m){
                string temp = s.substr(i, m);
                if(mp.find(temp) == mp.end()){
                    left = i + m;
                    seen.clear();
                    curr_len = 0;
                }else{
                    seen[temp]++;
                    curr_len++;
                    while(seen[temp] > mp[temp]){
                        string tp = s.substr(left, m);
                        seen[tp]--;
                        curr_len--;
                        left += m;
                    }
                }
                if(curr_len == w){
                    ans.push_back(left);
                    string t = s.substr(left, m);
                    seen[t]--;
                    curr_len--;
                    left += m;
            }
                
        }
            
        }
        return ans;
    }
};