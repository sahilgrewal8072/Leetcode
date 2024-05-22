class Solution {
    private:
    bool dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &color){
        if(parent == -1){
            color[node] = 0;
        }else{
            color[node] = !color[parent];
        } 
        
        for(auto it : graph[node]){
            if(color[it] == -1){
                if(!dfs(it, node, graph, color))return false;;
            }else if(color[it] != -1){
                if(color[it] == color[node])return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        if(v == 1)return true;
        vector<int> color(v, -1);
        for(int i = 0; i<v; i++){
            if(color[i] == -1){
                if(!dfs(i, -1, graph, color))return false;
            }
        }
        return true;
    }
};