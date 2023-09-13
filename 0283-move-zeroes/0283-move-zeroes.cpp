class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] != 0)continue;
            int j = i + 1;
            while(j < n && nums[j] == 0){
                j++;
            }
            if(i < n && j < n)
            swap(nums[i], nums[j]);
            if(j == n-1)break;
        }
    }
};