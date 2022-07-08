class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int cur_xor = 0;
        for(int i=0; i<n; i++){
            cur_xor = cur_xor^nums[i];
        }
        
        int tmp = cur_xor;
        int pos = 0;
        while((tmp&1) == 0){
            pos++;
            tmp >>= 1;
        }
        
        int mask = (1 << pos);
        int curr_xor2 = 0;
        for(int i=0; i<n; i++){
            if(mask&nums[i]){
                curr_xor2 = curr_xor2^nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(curr_xor2);
        ans.push_back(curr_xor2^cur_xor);
        return ans;
    }
};