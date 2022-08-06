#define ll long long
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<ll,ll> mp;
        int n = tasks.size();
        ll curr_day = 0 + 1;
        for(int ind=0;ind<n;ind++){
            if(mp.find(tasks[ind]) == mp.end()){
                mp[tasks[ind]] = curr_day;
                curr_day += 1;
            }else if(curr_day - mp[tasks[ind]] < space || curr_day - mp[tasks[ind]] == space){
                 ll gap = curr_day - mp[tasks[ind]];
                curr_day += (space - gap + 1);
                mp[tasks[ind]] = curr_day;
                curr_day++;
            }else{ 
                mp[tasks[ind]] = curr_day;
                curr_day++;
            }
        }
        ll ans = --curr_day;
        return ans;
    }
};