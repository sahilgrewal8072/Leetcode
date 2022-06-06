class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)return {0};
        vector<int> adj[n];
        int u, v;
        vector<int> indegree(n, 0);
        for(int i=0; i<edges.size(); i++){
            u = edges[i][0];
            v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[v]++;
            indegree[u]++;
        }
        queue<int> q;
       for(int i=0; i<n; i++){
           if(indegree[i] == 1){
               q.push(i);
           }
       }
        vector<int> ans;
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0; i<s; i++){
                 int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto it : adj[node]){
                    indegree[it]--;
                    if(indegree[it] == 1){
                        q.push(it);
                    }
                }
            }
        }

        return ans;
    }
};