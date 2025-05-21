class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }

            int nxt_warmer_day = st.size() > 0 ? st.top() - i : 0;
            ans[i] = nxt_warmer_day;
            st.push(i);
        }
        return ans;
    }
};