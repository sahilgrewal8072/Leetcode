class Solution {
public:
    
    vector<string> turn(string s, int pos){
        vector<string> res(2, s);
        res[0][pos] = '0' + (res[0][pos] - '0' + 1)%10;
        res[1][pos] =  '0' + (res[1][pos] - '0' - 1 + 10)%10;
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> mp2(begin(deadends), end(deadends)), mp({"0000"});
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        if(mp2.find("0000") != mp2.end())return -1;
        while(!q.empty()){
            string s = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(s == target)return lvl; 
                for(int pos = 0; pos < 4; pos++){ 
                    for(auto it : turn(s, pos)){
                        if(mp.find(it) == mp.end() && mp2.find(it) == mp.end()){
                            if(it == target){
                                return lvl + 1;
                            }
                            mp.insert(it);
                            q.push({it, lvl + 1});
                        }
                    }   
                }    
        }
        return -1;
    }
};