class Solution {
    private:
    bool isPossible(int &dist, int &m, vector<int> &pos, int &n){
        int last_pos = pos[0];
        int used = 1;
        for(int i=1; i<n; i++){
            int curr_pos = pos[i];
            if(curr_pos - last_pos >= dist){
                used++;
                last_pos = curr_pos;
                if(used == m){
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 0;
        int high = position[n-1] - position[0];
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, m, position, n)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};