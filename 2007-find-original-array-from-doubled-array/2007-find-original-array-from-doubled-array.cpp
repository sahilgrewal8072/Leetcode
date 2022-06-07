class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n&1)return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[changed[i]]++;
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mp[changed[i]] == 0)continue;
            mp[changed[i]]--;
            if(mp[2*changed[i]] > 0){
                mp[2*changed[i]]--;
                ans.push_back(changed[i]);
            }else{
                return {};
            }
        }
        return ans;
    }
};