class Solution {
    
    private:
        vector<int> parent, size;
        public:
       void DSU(int n){
            parent.resize(n+1);
            size.resize(n+1, 0);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }
        
        
        int find_parent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = find_parent(parent[node]);
        }
    
    bool isConnected(int u, int v){
        return (find_parent(u) == find_parent(v));
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
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        DSU(m*n);
        // dummy will be present at pos m*n
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    union_size(i*n + j, m*n);
                }else if(board[i][j] == 'O'){
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(board[nx][ny] == 'O'){
                            union_size(i*n + j, nx*n + ny);
                        }
                    }
                }
                
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!isConnected(i*n + j, m*n)){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};