class Solution{
    private:
    long long int atmostK(vector<int> &arr, long long k, int n){
        long long int right = 0;
        long long int left = 0;
        long long int sum = 0;
        long long int count = 0;
        for(right = 0; right < n; right++){
            sum += arr[right];
            while(sum*(right - left + 1) >= k){
                sum -= arr[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        return atmostK(nums, k, n);
    }
};