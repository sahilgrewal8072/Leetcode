// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long solve(int N, vector<long long> &dp){
        if(N <= 3){
            return 1;
        }
        
        if(dp[N] != -1)return dp[N];
        return dp[N] = solve(N-1, dp) + solve(N-4, dp);
    }

    long long int arrangeTiles(int N){
        // code here
        vector<long long> dp(N+1, -1);
        return solve(N, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends