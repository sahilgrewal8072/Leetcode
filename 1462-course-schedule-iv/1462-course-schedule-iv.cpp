class Solution {
public:
    
    

    void dfs(int node, int parent, vector<int> adj[], vector<vector<int>> &check){
        for(auto it : adj[node]){
                if(check[parent][node] == -1)
                dfs(it, parent, adj, check);
        }
        
        if(node != parent){
            check[parent][node] = 1;
        }else{
            check[parent][node] = 0;
        }
    }
    
    vector<bool> checkIfPrerequisite(int nodes, vector<vector<int>>& preq, vector<vector<int>>& queries) {
        int edges = preq.size();
        vector<bool> ans(queries.size(), false);
        if(edges == 0)return ans;
        vector<int> adj[nodes];
        int u, v;
        for(auto it : preq){
            u = it[0];
            v = it[1];
            adj[u].push_back(v);
        }
        vector<vector<int>> check(nodes, vector<int>(nodes, -1));
        for(int i=0; i<nodes; i++){
            dfs(i, i, adj, check);
        }
      
        
        for(int i=0; i<ans.size(); i++){
            if(check[queries[i][0]][queries[i][1]] == 1){
                ans[i] = true;
            }
        }
        return ans;
    }
};