class Solution {
    private:
    void dfs(int node, vector<int> adj[], vector<int> &visited){
        visited[node] = 1;

        for(auto it : adj[node]){
            if(visited[it] == -1)
            dfs(it, adj, visited);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        // queue<int> q;
        vector<int> visited(n, -1);
        int count = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == -1){
                count++;
                dfs(i, adj, visited);
            }   
        }
        return count;
    }
};