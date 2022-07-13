class Solution {
    private:
    int merge(vector<int> &arr, int &s, int &e){
        int count = 0;
        int i = s;
        int mid = (s + e)/2;
        int j = mid + 1;
        for(i = s; i <= mid; i++){
            while(j <= e && arr[i] > 1ll*2*arr[j]){
                j++;
            }
            count += (j - (mid + 1));
        }
        sort(arr.begin() + s, arr.begin() + e + 1);
        return count;
    }
    
    
    int inversion_count(vector<int> &arr, int s, int e){
        if(s >= e)return 0;
        int mid = (s + e)/2;
        int count = inversion_count(arr, s, mid);
        count += inversion_count(arr, mid + 1, e);
        count += merge(arr, s, e);
        return count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        int count = inversion_count(nums, 0, n-1);
        return count;
    }
};