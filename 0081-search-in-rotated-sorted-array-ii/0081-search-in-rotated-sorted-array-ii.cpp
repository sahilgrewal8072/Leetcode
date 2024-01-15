class Solution {
public:
    bool search(vector<int>& arr, int target) {
        // classy question must revise
            int low = 0;
        int n  = arr.size();
        int high = n - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] == arr[low] && arr[high] == arr[mid]){
                    low++;
                    high--;
            }else if(arr[mid] > arr[high]){
                if(target < arr[mid] && target >= arr[low]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(target > arr[mid] && target <= arr[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};