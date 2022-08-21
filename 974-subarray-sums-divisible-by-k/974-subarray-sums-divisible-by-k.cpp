class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int curr_rem = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            curr_rem = sum%k;
            if(curr_rem < 0){
                curr_rem += k;
            }
            if(mp.find(curr_rem) != mp.end()){
                count += mp[curr_rem];
            }
            mp[curr_rem]++;
        }
        return count;
    }
};