// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string equilibrium(int *arr, int n) {
        // code here
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i]; 
        }
        
        for(int i = n-2; i>=0; i--){
            suffix[i] = suffix[i+1] + arr[i];
        }
        
        for(int i=0; i<n; i++){
            int left = 0;
            int right = 0;
            if(i - 1 >= 0){
                left = prefix[i-1];
            }
            if(i + 1 < n)
            right = suffix[i + 1];
            if(left == right){
                return "YES";
            }
        }
        return "NO";
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.equilibrium(a, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends