class Solution {
public:
    
    // follow up of leetcode 907
    
    long long sumSubarrayMin(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        long long int sum = 0;
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
                sum += (long long)(arr[j] * (right*left));
            }
            st.push(i);
        }
        return sum;
        
    }
    
    long long sumSubarrayMax(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        long long int sum = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()] < arr[i])){
                int j = st.top();
                st.pop();
               long long int right = i - j;
               long long int prevTop = -1;
                if(!st.empty()){
                    prevTop = st.top();
                }
                int left = j - prevTop;
                sum += (long long)(arr[j] * (right*left));
            }
            st.push(i);
        }
        return sum;
        
    }
    
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);
    }
};