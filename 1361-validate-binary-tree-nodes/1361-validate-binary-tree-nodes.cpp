class Solution {
    private:
    bool solve(int node, vector<int> adj[], vector<int> &visited){
        if(visited[node] == 1)return false;
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!solve(it, adj, visited))return false;
        }
        return true;
    }
    
    
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }         
            
        }
        int root_node = n;
        int mn = 1e8;
        for(int i=0; i<n; i++){
            if(indegree[i] < mn){
                root_node = i;
                mn = indegree[i];
            }
        }
        vector<int> visited(n, 0);
        bool ans = solve(root_node, adj, visited);
        for(int i=0; i<n; i++){
            if(!visited[i])return false;
        }
        return ans;
    }
};