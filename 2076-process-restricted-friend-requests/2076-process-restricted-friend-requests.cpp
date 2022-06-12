
class Solution {
    public:
    vector<int> size;
    vector<int> parent;
    void DSU(int n){
        size.resize(n, 0);
        parent.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    private:
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
            parent[v] = u;
            size[u] += size[v];
        }else{
            parent[u] = v;
            size[v] += size[u];
        }
    }
    
public:
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU(n);
        int m = requests.size();
        vector<bool> ans(m, false);
        int i = 0;
        for(auto &it : requests){
            int u = it[0], v = it[1];
            u = find_parent(u);
            v = find_parent(v);
            bool flag = true;
            for(auto &it : restrictions){
                int x = it[0], y = it[1];
                x = find_parent(x);
                y = find_parent(y);
                if(u == x && v == y || u == y && v == x){
                    flag = false;
                    break;
                }
            }
            if(flag)union_size(u, v);
            ans[i++] = flag;
        }
        
        return ans;
    }
};