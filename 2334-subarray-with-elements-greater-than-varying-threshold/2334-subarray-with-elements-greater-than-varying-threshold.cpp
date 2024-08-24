class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        stack<int> st;
        vector<int> nxt_smaller(n, -1);
        vector<int> prev_smaller(n, -1);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < nums[st.top()]){
                nxt_smaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[i] < nums[st.top()]){
                prev_smaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i = 0; i < n; i++){
            int left = prev_smaller[i];
            int right = nxt_smaller[i] == -1 ? n : nxt_smaller[i];
            int k = right - left - 1;
            if(nums[i] > (threshold/k)){
                return k;
            }
        }
        return -1;
    }
};