class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == 0)return 0;
            return n;
        }
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                s.insert(nums[i]);
            }
        }

        
        return s.size();
    }
};