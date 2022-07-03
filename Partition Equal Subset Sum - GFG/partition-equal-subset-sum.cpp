// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int ind, int arr[], int sum, int curr, vector<vector<int>> &dp){
        if(ind < 0){
            return 0;
        }
        if(curr == sum)return 1;
        if(dp[ind][curr] != -1)return dp[ind][curr];
        
        int take = 0;
        if(arr[ind] + curr <= sum)
        take =  solve(ind - 1, arr, sum, curr + arr[ind], dp);
        int notake = solve(ind - 1, arr, sum, curr, dp);
        return dp[ind][curr]  = (take || notake);
    }

    int equalPartition(int n, int arr[])
    {
        // code here
       int sum = 0;
       for(int i=0; i<n; i++)sum += arr[i];
       if(sum&1)return 0;
       vector<vector<int>> dp(n, vector<int>(sum+1, -1));
       return solve(n-1, arr, sum/2, 0, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends