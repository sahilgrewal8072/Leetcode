class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        int mx = 0;
        int cover = 0;
        int j = 0;
        int i=0;
        while(i<n){
            if(j == i || tiles[j][0] + carpetLen > tiles[i][1]){
                cover += (tiles[i][1] - tiles[i][0] + 1);
                mx = max(mx, cover);
                i++;
            }else{
                mx = max(mx, cover + max(0, tiles[j][0] + carpetLen - tiles[i][0]));
                cover -= (tiles[j][1] - tiles[j][0]  +  1);
                j++;
            }
        }
        return min(carpetLen,mx);
    }
};