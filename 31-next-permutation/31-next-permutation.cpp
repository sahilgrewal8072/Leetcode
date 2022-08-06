class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int point = 0;
        int n = arr.size();
        int i = n-1;
        for(i=n-1; i>0; i--){
            if(arr[i] > arr[i-1])break;
        }
        point = i-1;
        
        if(i == 0){
            reverse(arr.begin(), arr.end());
            return;
        }
        
        for(int j=n-1; j>point; j--){
            if(arr[j] > arr[point]){
                swap(arr[j], arr[point]);
                break;
            }
        }
        
        reverse(arr.begin() + i, arr.end());
    }
};