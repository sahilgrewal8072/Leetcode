class Solution {
    private:
    bool dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &ans, vector<int> &pathvisited){
        visited[node] = 1;
        pathvisited[node] = 1;
        ans.push_back(node);

        for(auto it : adj[node]){
            if(!visited[it]){
                if(!dfs(it, visited, adj, ans, pathvisited))return false;
            }else if(pathvisited[it] == 1){
                return false;
            }
        }
        pathvisited[node] = 0;
        return true;
    }
public:
    bool canFinish(const int numCourses, vector<vector<int>>& pre) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
         for(auto it : pre){
             int u = it[0];
             int v = it[1];
             adj[v].push_back(u);
             indegree[u]++;
         }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int nodevisited = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodevisited++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return nodevisited == numCourses;

    }
};