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
        
        bool union_size(int u, int v){
            u = find_parent(u);
            v = find_parent(v);
            if(u == v)return false;
            if(size[u] > size[v]){
                parent[v]  = u;
                size[u] += size[v];
            }else{
                parent[u] = v;
                size[v] += size[u];
            }
            return true;
        }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU(n);
        int a1 = 0;
        int a2 = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(union_size(u, v) == false){
                a1 = u;
                a2 = v;
            }
        }
        return {a1, a2};
    }
};