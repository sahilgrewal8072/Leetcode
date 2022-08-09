#define ll long long
int mod = 1e9 + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        sort(arr.begin(), arr.end());
        unordered_map<ll, ll> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]] = 1;
            long long count = 0;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]  == 0){
                    count = (count%mod + mp[arr[j]]*mp[arr[i]/arr[j]])%mod;
                }
            }
            mp[arr[i]] += count;
            ans = (ans%mod + mp[arr[i]])%mod;
        }
        return ans;
    }
};