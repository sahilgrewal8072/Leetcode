class Solution {
public:
    vector<int> visited;
    void dfs(int node, vector<int> adj[]){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];
        visited.resize(n, 0);
        int u, v;
        for(int i=0; i<n; i++){
            for(auto it : rooms[i]){
                adj[i].push_back(it);
            }
        }
        dfs(0, adj);
        
        for(auto it : visited){
            if(it == 0)return false;
        }
            return true;
        }
};