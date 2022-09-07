class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        string ans = "";
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        
        while(pq.size() > 1){
            auto ele_1 = pq.top();
            pq.pop();
            auto ele_2 = pq.top();
            pq.pop();
            
            ele_1.first--;
            ele_2.first--;
            
            ans += ele_1.second;
            ans += ele_2.second;
            
            if(ele_1.first > 0){
                pq.push(ele_1);
            }
            
            if(ele_2.first > 0){
                pq.push(ele_2);
            }
        }
        if(!pq.empty()){
            if(pq.top().first > 1){
            return "";
        }else{
            ans += pq.top().second;
            pq.pop();
        }
        }
        
        return ans;
    }
};