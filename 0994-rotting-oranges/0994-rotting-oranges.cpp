// class Node{
//     public:
//     int x;
//     int y;
//     int count;
//     Node(int x, int y, int count){
//         this->x  = x;
//         this->y = y;
//         this->count = count;
//     }
// };

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<Node> q;
//         int fresh = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m ; j++){
//                 if(grid[i][j] == 2){
//                     q.push({i, j, 0});
//                 }

//                 if(grid[i][j] == 1)fresh++;
//             }
//         }

//         int min = 0;
//         int dx[] = {-1, 1, 0, 0};
//         int dy[] = {0, 0, -1, 1};
//         while(!q.empty()){
//             int x = q.front().x;
//             int y = q.front().y;
//             int c_count = q.front().count;
//             q.pop();
//             for(int i = 0; i < 4; i++){
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
//                     grid[nx][ny] = 2;
//                     q.push({nx, ny, c_count+1});
//                     min = max(min, c_count + 1);
//                     fresh--;
//                 }
//             }
//         }
//         if(fresh != 0)return -1;
//         return min;
//     }
// };

class Solution {

    
public:
    int orangesRotting(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 2){
                    q.push({i, j});
                }

                if(rooms[i][j] == 1){
                    fresh++;
                }
            }
            
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int distance = 0;
        
        while(!q.empty() && fresh > 0){
            int size = q.size();
            
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && rooms[nx][ny] == 1){
                        rooms[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            distance++;
        }
        if(fresh != 0)return -1;
        return distance;
        
    }
};