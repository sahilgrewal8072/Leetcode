class Solution {
    private:
    int subarraySum(vector<int>& arr, int k) {
         unordered_map<int, int> mp;
        int n = arr.size();
    int i;
    int diff = 0;
    int sum =0;
    int count = 0;
    for(i=0; i<n; i++){
        sum += arr[i];
        if(sum == k){
            count++;
        }
        diff = sum - k;
        if(mp.find(diff) != mp.end()){
            count += mp[diff];
        }
        mp[sum]++;
    }
    return count;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int rowSt = 0; rowSt < n; rowSt++){
            vector<int> arr(m, 0);
            for(int i = rowSt; i < n; i++){
                for(int j = 0; j<m; j++){
                    arr[j] += matrix[i][j];
                }
                ans += subarraySum(arr, target);
            }
        }
        return ans;
    }
};