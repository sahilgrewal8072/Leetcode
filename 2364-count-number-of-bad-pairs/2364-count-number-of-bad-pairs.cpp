#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<ll, ll> mp;
        int n = nums.size();
        ll count = 0;
        for(int i=0; i<n; i++){
            count += mp[i - nums[i]];
            mp[i - nums[i]]++;
        }
        
        ll total = n*1ll*(n-1)/2;
        return total - count;
    }
};