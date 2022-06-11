class Solution {
    private:
    int atmostK(vector<int> &arr, int k, int n){
        unordered_map<int,int> mp;
        int right = 0;
        int left = 0;
        int count = 0;
        for(right = 0; right < n; right++){
            mp[arr[right]]++;
            while(mp.size() > k){
                mp[arr[left]]--;
                if(mp[arr[left]] == 0){
                    mp.erase(arr[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int x = atmostK(nums, k, n);
        cout<<x<<endl;
        int y = atmostK(nums, k-1, n);
        cout<<y<<endl;
        return  x - y;
    }
};