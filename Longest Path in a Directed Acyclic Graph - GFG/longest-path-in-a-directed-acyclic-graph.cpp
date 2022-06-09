// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
vector<int> visited;
stack<int> st;

class Solution
{
    public:
    
    void dfs_topo(vector<pair<int, int>> adj[] , int node) {
	visited[node] = 1;
	for (auto it : adj[node]) {
		if (!visited[it.first]) {
			dfs_topo(adj, it.first);
		}
	}
	st.push(node);
}
    
    
   
    
      vector <int> maximumDistance(vector<vector<int>> edges,int n,int m,int src)
      {
            // code here
            
            visited.resize(n, 0);
		vector<pair<int, int>> adj[n];
		vector<int> indegree(n, 0);
		int u, v, w;
		for (int i = 0; i < m; i++) {
			u = edges[i][0];
			v = edges[i][1];
			w = edges[i][2];
		    indegree[v]++;
			adj[u].push_back({v, w});
		}
            queue<int> q;
            for(int i=0; i<n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            
    //         for (int i = 0; i < n; i++) {
			 //   if (!visited[i])dfs_topo(adj, i);
    //         }
            
        vector<int> minDist(n, INT_MIN);
		minDist[src] = 0;
		
		vector<int> topo;
		while(!q.empty()){
		    int node = q.front();
		    q.pop();
		    topo.push_back(node);
		    for(auto it : adj[node]){
		        indegree[it.first]--;
		        if(indegree[it.first] == 0){
		            q.push(it.first);
		        }
		    }
		}
// 		for(auto it : topo)cout<<it<<" " ;
		for(auto it : topo){
		    for(auto i : adj[it]){
		        int u = it;
		        int v = i.first;
		        int wt = i.second;
		        if(minDist[u] == INT_MIN)continue;
		        if(minDist[u] + wt > minDist[v]){
		            minDist[v] = minDist[u] + wt;
		        }
		    }
		}
		return minDist;
      }
};

// { Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}  // } Driver Code Ends