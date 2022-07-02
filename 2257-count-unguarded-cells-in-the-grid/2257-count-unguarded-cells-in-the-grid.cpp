class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(auto &it : guards){
            int x = it[0];
            int y = it[1];
            visited[x][y] = 2;
        }
        
        for(auto &it  : walls){
            int x = it[0];
            int y = it[1];
            visited[x][y] = -2;
        }
        
        for(auto &it : guards){
            int x = it[0];
            int y = it[1];
            
            // left
            for(int i = y-1; i>= 0; i--){
                if(visited[x][i] == 2 || visited[x][i] == -2)break;
                visited[x][i] = 1;
            }
            
            //right
            for(int i = y + 1; i<n; i++){
                if(visited[x][i] == 2 || visited[x][i] == -2)break;
                    visited[x][i] = 1;
            }
            
            //top
            for(int i = x-1; i >= 0 ; i--){
                if(visited[i][y] == 2 || visited[i][y] == -2)break;
                    visited[i][y] = 1;
            }
            
            // down
             //top
            for(int i = x+1; i<m ; i++){
                if(visited[i][y] == 2 || visited[i][y] == -2)break;
                    visited[i][y] = 1;
            }
        }
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j] == 0)count++;
            }
        }
        return count;
    }
};