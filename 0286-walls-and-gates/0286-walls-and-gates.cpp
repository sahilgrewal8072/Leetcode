class Solution {

    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int distance = 0;
         int emptyRoom = 2147483647;
        while(!q.empty()){
            int size = q.size();
            distance++;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && rooms[nx][ny] == emptyRoom){
                        rooms[nx][ny] = distance;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
    }
};