class Solution {
public:
    // Maha important sum
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        // ple = previous less element 
        // nle = next less element
        stack<pair<int, int>> ple, nle;
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        for(int i=0; i<n; i++){
            right[i] = n - i;
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            while(!ple.empty() && arr[ple.top().second] > arr[i])ple.pop();
            left[i] = (ple.empty()) ? i+1 : i - ple.top().second;
            ple.push({arr[i], i});
            
            
            while(!nle.empty() && arr[nle.top().second] > arr[i]){
                int ind = nle.top().second;
                nle.pop();
                right[ind] = i - ind;
            }
            nle.push({arr[i], i});
        }
        
        for(int i=0; i<n; i++){
            sum += (arr[i]*1ll*(left[i]*right[i])%mod)%mod;
            sum %= mod;
        }
        return sum;
    }
};