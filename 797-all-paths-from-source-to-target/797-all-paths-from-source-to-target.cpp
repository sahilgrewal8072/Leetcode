class Solution {
public:
    
    void dfs(int node, vector<int> adj[], vector<int> temp, vector<vector<int>> &ans, int n){
        temp.push_back(node);
        if(node == n)
        {
            ans.push_back(temp);
        }
        
        for(auto it : adj[node]){
                dfs(it, adj, temp, ans, n);
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // since this is a DAG there is no need of visited array
        int n = graph.size();
        int u, v;
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j = 0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, adj, temp, ans, n-1);
        return ans;
    }
};