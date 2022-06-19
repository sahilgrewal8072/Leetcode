class Solution {
public:
    long long int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()] > arr[i])){
                int j = st.top();
                st.pop();
               long long int right = i - j;
               long long int prevTop = -1;
                if(!st.empty()){
                    prevTop = st.top();
                }
                int left = j - prevTop;
                sum += (long long)(arr[j] * (right*left)%mod)%mod;
                sum %= mod;
            }
            st.push(i);
        }
        return sum%mod;
    }
};