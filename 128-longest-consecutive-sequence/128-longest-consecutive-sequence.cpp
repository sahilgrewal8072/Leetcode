class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        
        for(auto it : nums){
            st.insert(it);
        }
        
        int mx = 0;
        for(int i=0; i<n; i++){
            if(!st.count(nums[i] - 1)){
                int x = nums[i];
                int count = 0;
                while(st.count(x)){
                    count++;
                    x += 1;
                }
                mx = max(count, mx);
            }
        }
        return mx;
    }
};