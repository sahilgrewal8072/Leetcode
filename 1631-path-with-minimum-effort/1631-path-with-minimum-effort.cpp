class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        dist[0][0] = 0;
        while(!pq.empty()){
            int c_dist = pq.top().first;
            int c_x = pq.top().second.first;
            int c_y = pq.top().second.second;
            pq.pop();
            if(c_x == n-1 && c_y == m - 1)return c_dist;
            for(int i = 0; i<4; i++){
                int nx = c_x + dx[i];
                int ny = c_y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int new_effort = max(c_dist, abs(heights[nx][ny] - heights[c_x][c_y]));
                    if(new_effort < dist[nx][ny]){
                        dist[nx][ny] = new_effort;
                        pq.push({new_effort, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};