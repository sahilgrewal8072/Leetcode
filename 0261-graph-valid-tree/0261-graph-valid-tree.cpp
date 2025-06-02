 class Solution {
    private:
    bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[]){
        visited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(!dfs(it, node, visited, adj))return false;
            }else if(it != parent){
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> visited(n, 0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                if(!dfs(i, -1, visited, adj))return false;
                if(count > 1)return false;
            }
        }
        cout<<count<<" ";
        return true;
    }
};