class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int  n = nums.size();
        if(n == 0)return 0;
        int mx = 1;
        unordered_set<int> mp(nums.begin(), nums.end());
        

        for(auto num : mp){
            if(!mp.count(num - 1)){
                 int curr_streak = 1;
                int curr_val = num;
                while(mp.count(curr_val + 1)){
                        curr_val++;
                        curr_streak++;
                }
                mx = max(mx, curr_streak);
            }   
        }
        return mx;
    }
};