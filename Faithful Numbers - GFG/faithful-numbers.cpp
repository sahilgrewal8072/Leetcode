// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long nthFaithfulNum(int N) {
        // code here
        long long ans = 0;
        long long fact = 1;
        while(N > 0){
            int last = N & 1;
            ans += (fact*last);
            fact *= 7;
            N >>= 1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.nthFaithfulNum(N) << endl;
    }
    return 0;
}  // } Driver Code Ends