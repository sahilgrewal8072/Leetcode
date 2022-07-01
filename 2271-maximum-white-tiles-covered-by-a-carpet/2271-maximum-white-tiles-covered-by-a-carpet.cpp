class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        vector<long long> prefix(n, 0);
        vector<int> diff(n, 0);
        
        for(int i=0; i<n; i++){
            diff[i] = tiles[i][1] - tiles[i][0];
        }
        
        prefix[0] = diff[0] + 1;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + diff[i] + 1;
        }
        // for(auto it : diff)cout<<it<<" ";
        long long mx = 0;
        for(int curr = 0; curr<n; curr++){
            int remain = carpetLen - (diff[curr] + 1);
            // cout<<used<<endl;
            int used = carpetLen - used;
            // cout<<remain<<endl;
            int nxt_ind = tiles[curr][1] + remain;
            // cout<<nxt_ind<<endl;
            vector<int> a = {nxt_ind, INT_MAX};
            int ind = upper_bound(tiles.begin(), tiles.end(), a) - tiles.begin();
            ind--;
            long long x = 0;
            long long y = 0;
            if(ind > 0){
                y = prefix[ind - 1];
            }
            if(curr > 0){
                x = prefix[curr - 1];
            }
            // case :1 
            if(tiles[ind][1] <= nxt_ind){
                 // cout<<curr<<" "<<ind<<" "<<nxt_ind<<" "<<prefix[ind] - x  + 1<<endl;
                mx = max(mx, prefix[ind] - x);
            }else{
                // cout<<curr<<" "<<ind<<" "<<nxt_ind<<" "<<y - x + nxt_ind - tiles[ind][0] + 1<<endl;
                mx = max(mx, y - x + nxt_ind - tiles[ind][0] + 1);
            }
           
        }
        return mx;
    }
};