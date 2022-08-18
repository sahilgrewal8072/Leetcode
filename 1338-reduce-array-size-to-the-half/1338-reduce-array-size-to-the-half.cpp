class Solution {

public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        vector<pair<int, int>> freq;
        for(auto &it : mp){
            freq.push_back({it.second, it.first});
        }
        
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());
        
        int curr = 0;
        for(int i=0; i<n; i++){
            curr += freq[i].first;
            if(curr >= n/2)return i + 1;
        }
        return 0;
    }
};