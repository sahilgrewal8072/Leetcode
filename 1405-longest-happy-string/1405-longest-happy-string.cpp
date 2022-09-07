class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        unordered_map<char, int> mp;
        string ans  = "";
        priority_queue<pair<int, char>> pq;
        if(a)
        mp['a'] = a;
        if(b)
        mp['b'] = b;
        if(c)
        mp['c'] = c;
        for(auto &it : mp){
            pq.push({it.second, it.first});
        }
        
        while(pq.size() > 1){
            auto ele_1 = pq.top();
            pq.pop();
            auto ele_2 = pq.top();
            pq.pop();
            
            int count1 = 0;
            int count2 = 0;
            while(count1 < 2 && ele_1.first > 0){
                ans += ele_1.second;
                count1++;
                ele_1.first--;
            }
            
            if(ele_2.first >= ele_1.first && ele_2.first >= 2){
                ans += ele_2.second;
                ans += ele_2.second;
                ele_2.first -= 2;
            }else{
                ans += ele_2.second;
                ele_2.first -= 1;
            }
            
            if(ele_1.first > 0){
                pq.push(ele_1);
            }
            
            if(ele_2.first > 0){
                pq.push(ele_2);
            }
        }
        // cout<<ans;
        if(!pq.empty()){
            int count = 0;
            int freq = pq.top().first;
            while(count < 2 && freq){
                ans += pq.top().second;
                count++;
                freq--;
            }
        }
        return ans;
    }
};