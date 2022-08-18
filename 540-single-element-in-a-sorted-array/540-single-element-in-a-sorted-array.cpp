class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)return arr[0];
        int low = 0;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid&1 && arr[mid] == arr[mid - 1] || mid%2 == 0 && arr[mid] == arr[mid+1]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return arr[low];
    }
};