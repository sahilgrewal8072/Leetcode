class Solution {
public:
    
    bool isValid(int toDo, vector<int> &task, vector<int> &workers, int pills, int strength){
        multiset<int> mp(workers.begin(), workers.end());
        for(int i=toDo-1; i>=0; i--){
            auto it = mp.end();
            it--;
            if(*it < task[i]){
                if(pills <= 0)return false;
                it  = mp.lower_bound(task[i] - strength);
                if(it == mp.end())return false;
                pills--;
            }
            mp.erase(it);
        }
        return true;
    }
    
    int maxTaskAssign(vector<int>& task, vector<int>& workers, int pills, int strength) {
        int low = 0;
        int mid;
        sort(task.begin(), task.end());
        sort(workers.begin(), workers.end());
        int high = min(task.size(), workers.size());
        int ans = 0;
        while(low <= high){
            mid = (low + high)/2;
            if(isValid(mid, task, workers, pills, strength)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};