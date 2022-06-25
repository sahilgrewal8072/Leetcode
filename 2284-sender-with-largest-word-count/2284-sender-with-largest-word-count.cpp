class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = senders.size();
        unordered_map<string, int> mp;
        int mx = 0;
        string ans = "";
        for(int i=0; i<n; i++){
            int words = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            mp[senders[i]] += words;
            if(mp[senders[i]] > mx || mp[senders[i]] == mx && senders[i] > ans){
                ans = senders[i];
                mx = mp[senders[i]];
            }
        }
        return ans;
    }
};