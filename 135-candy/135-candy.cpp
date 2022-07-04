class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n, 0);
        arr[0] = 1;
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                arr[i] = arr[i-1] + 1;
            }else{
                arr[i] = 1;
            }
        }
         // for(auto it : arr)cout<<it<<" ";
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                if(arr[i] <= arr[i+1])
                arr[i] = (arr[i+1] + 1);
            }
        }
        
        int sum = 0;
        for(auto it : arr)sum += it;
        return sum;
    }
};