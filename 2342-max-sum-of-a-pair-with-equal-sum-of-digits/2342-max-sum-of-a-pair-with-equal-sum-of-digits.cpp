class Solution {
    private:
    int solve(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[solve(nums[i])].push_back(i);
        }
        
        int ans = -1;
        for(auto &it : mp){
            if(it.second.size() >= 2){
                ans = max(ans, nums[it.second[0]] + nums[it.second[1]]);
            }
        }
        return ans;
    }
};