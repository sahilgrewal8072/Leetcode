class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int count = 0;
        unordered_set<int> st;
        for(auto it : nums){
            st.insert(it);
        }

        for(int i=0; i<n; i++){
            if(!st.count(nums[i] - 1)){
                int x = nums[i];
                 count = 0;
                 while(st.count(x)){
                     count++;
                     x += 1;
                 }
            }
            mx = max(mx, count);
        }
        return mx;
    }
};
