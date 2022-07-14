// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int countFlips(int arr[],int n)
    {
        //code here.
        int state = 0;
        for(int i=0; i<n-1; i++){
            if(arr[i] != arr[i+1]){
                state++;
            }
        }
        
        if(arr[0] == 0){
            return state + 1;
        }
        return state;
    }
};


// { Driver Code Starts.
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        cout<<ob.countFlips(a,n)<<endl;
    }
    return 0;
}

  // } Driver Code Ends