class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx_degree = 0;
        unordered_map<int, int> left, right, count;
        for(int i=0; i<n; i++){
            if(left.find(nums[i]) == left.end())
            {
                left[nums[i]] = i;
            }
            
            right[nums[i]] = i;
            count[nums[i]]++;
            mx_degree = max(mx_degree, count[nums[i]]);
        }
        
        int ans = n;
        for(auto &it : count){
            if(it.second == mx_degree){
                ans = min(ans, right[it.first] - left[it.first]  + 1);
            }
        }
        return ans;
    }
};