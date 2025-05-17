class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prev(n, 1);
        prev[0] = nums[0];
        for(int i = 1; i < n; i++){
            prev[i] = prev[i-1]*nums[i];
        }

        int right = 1;
        for(int i = n - 1; i >= 0; i--){

            int left = i-1 < 0 ? 1 : prev[i-1];
            prev[i] = left*right;
            right = right*nums[i];
        }

        return prev;
    }
};