class Solution {
public:
    
    

    void dfs(int node, int parent, vector<int> adj[], vector<vector<int>> &dp){
        if(dp[parent][node] != -1)return;
        for(auto it : adj[node]){
                if(dp[parent][node] == -1){
                    dfs(it, parent, adj, dp);
                }
                
        }
        
        if(node != parent){
            dp[parent][node] = 1;
        }else{
            dp[parent][node] = 0;
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
        vector<vector<int>> dp(nodes, vector<int>(nodes, -1));
        for(int i=0; i<nodes; i++){
            dfs(i, i, adj, dp);
        }
     
        for(int i=0; i<ans.size(); i++){
            if(dp[queries[i][0]][queries[i][1]] == 1){
                ans[i] = true;
            }
        }
        return ans;
    }
};