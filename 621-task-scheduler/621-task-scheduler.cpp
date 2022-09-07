class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        priority_queue<pair<int, char>> pq;
        int cycle = n + 1;
        int time = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        for(int i=0; i<len; i++){
            mp[tasks[i]]++;
        }
        
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        
        while(!pq.empty()){
            time = 0;
            vector<pair<int, char>> temp;
            for(int i=0; i<cycle; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            
            for(auto it : temp){
                if(--it.first){
                    pq.push(it);
                }
            }
            
            ans += (!pq.empty()) ? cycle : time;
        }
        return ans;
    }
};