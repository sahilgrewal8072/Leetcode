class Solution {
public:
    
    bool isCycle(int node, int parent, vector<int> adj[], vector<int> &visited){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(isCycle(it, node, adj, visited))return true;
            }else if(visited[it] && it != parent){
                return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edge) {
        int n = edge.size();
        int m  = edge[0].size();
        vector<int> adj[n+1];
        int u, v;
        vector<int> visited(n+1, 0);
        for(auto it : edge){
            fill(begin(visited), end(visited), 0);
            u = it[0];
            v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(isCycle(it[0], -1, adj, visited))return it;
        }
       
        return {};
    }
};