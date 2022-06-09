class Solution {
public:
    
    int cycleStart = -1;
    void isCycle(int node, int parent, vector<int> adj[], vector<int> &visited, unordered_set<int> &stt){
       if(visited[node]){
           cycleStart  = node;
           return;
       }
        
        visited[node] = 1;
        for(auto it : adj[node]){
            if(it == parent)continue;
            if(stt.empty())isCycle(it, node, adj, visited, stt);
            if(cycleStart != -1)stt.insert(node);
            if(node == cycleStart){
                cycleStart = -1;
                return;
            }
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edge) {
        int n = edge.size();
        int m  = edge[0].size();
        unordered_set<int> stt;
        vector<int> adj[n+1];
        int u, v;
        vector<int> visited(n+1, 0);
        for(auto it : edge){
            // fill(begin(visited), end(visited), 0);
            u = it[0];
            v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
            isCycle(1, 0, adj, visited, stt);   
        
        for(int i = n-1; i>= 0; i--){
            if(stt.count(edge[i][0]) && stt.count(edge[i][1]))return edge[i];
        }
       
        return {};
    }
};