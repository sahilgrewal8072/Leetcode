// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
int M = 1e9 + 7;
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<int> dp(n + 1, 1);
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1] + (i-1)*1ll*dp[i-2])%M;
            dp[i] %= M;
        }
        return dp[n]%M;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends