// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    private:
    int solve(int city, int visited, vector<vector<int>> &cost, int n, vector<vector<int>> &dp){
        if(visited == (1<<n) - 1){
            return cost[city][0];
        }
        if(dp[visited][city] != -1)return dp[visited][city];
        int ans = INT_MAX;
        for(int choice = 0; choice < n; choice++){
            // Check first if city is visited or not
            if(!((1 << choice) & visited)){
                int subPro = cost[city][choice] + solve(choice, (visited | (1<<choice)), cost, n, dp);
                ans = min(ans, subPro);
            }
        }
        return dp[visited][city] = ans;
    }
    
    
public:
int total_cost(vector<vector<int>>cost){
    // Code here
    int n = cost.size();
    vector<vector<int>> dp((1<<n), vector<int> (n, -1));
    int  visited = 1;
    return solve(0, visited, cost, n, dp);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends