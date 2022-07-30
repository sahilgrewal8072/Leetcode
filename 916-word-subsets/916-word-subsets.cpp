class Solution {
    private:
    vector<int> find_freq(string &s){
        int n = s.length();
        vector<int> curr_freq(26, 0);
        for(int i=0; i<n; i++){
            curr_freq[s[i] - 97]++;
        }
        return curr_freq;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<int> hash(26, 0);
        for(auto &it : words2){
            vector<int> curr = find_freq(it);
            for(int i=0; i<26; i++)hash[i] = max(hash[i], curr[i]);
        }
        vector<string> ans;
        for(auto &it : words1){
            int i=0; 
            vector<int> curr = find_freq(it);
            for(; i<26; i++){
                if(curr[i] < hash[i])break;
            }
            if(i == 26)ans.push_back(it);
        }
        return ans;
    }
};