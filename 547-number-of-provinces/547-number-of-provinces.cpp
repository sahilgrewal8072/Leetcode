class Solution {
    
    
        private:
        vector<int> parent, size;
        public:
       void DSU(int n){
            parent.resize(n+1);
            size.resize(n+1, 0);
            for(int i=1; i<=n; i++){
                parent[i] = i;
            }
        }
        
        
        int find_parent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = find_parent(parent[node]);
        }
        
        void union_size(int u, int v){
            u = find_parent(u);
            v = find_parent(v);
            if(u == v)return;
            if(size[u] > size[v]){
                parent[v]  = u;
                size[u] += size[v];
            }else{
                parent[u] = v;
                size[v] += size[u];
            }
        }
    
    
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        int count = 0;
        DSU(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               if(graph[i][j] == 1){
                   union_size(i+1, j+1);
               }
            }
        }
        
        for(int i=1; i<=n; i++){
            if(parent[i] == i)count++;
        }
        return count;
    }
};