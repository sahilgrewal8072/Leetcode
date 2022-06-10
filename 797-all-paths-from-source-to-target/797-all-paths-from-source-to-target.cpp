class Solution {
public:
    
    vector<int> visited;
    void dfs(int node, vector<int> adj[], vector<int> temp, vector<vector<int>> &ans, int n){
        visited[node] = 1;
        temp.push_back(node);
        if(node == n)
        {
            ans.push_back(temp);
        }
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, temp, ans, n);
            }
        }
        
        visited[node] = 0;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int u, v;
        visited.resize(n, 0);
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j = 0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        // for(int i=0; i<n; i++){
        //     for(auto it : adj[i]){
        //         cout<<i<<"->"<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> ans;
        vector<int> temp;
        // temp.push_back(0);
        dfs(0, adj, temp, ans, n-1);
        // for(auto it : visited)cout<<it<<" ";
        return ans;
    }
};