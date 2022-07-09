class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1){
            return true;
        }
        if(arr[0] == 0)return false;
        int reach = 0;
        for(int i=0; i<n; i++){
            if(i + arr[i] > reach){
                reach = i + arr[i];
            }
            if(i == reach){
                return false;
            }
            
            if(reach >= n-1){
                return true;
            }
        }
        return false;
    }
};