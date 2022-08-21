class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int right = 0;
        int left = -1;
        for(int i=0; i<n; i++){
            right = i;
            if(nums[i] >= 0){
                break;
            }
        }
        
        vector<int> ans(n);
        left = right - 1;
        int i = 0;
        while(left >= 0  && right < n){
            if(abs(nums[left]) <= abs(nums[right])){
                ans[i++] = (nums[left]*nums[left]);
                left--;
            }else{
                ans[i++] = (nums[right]*nums[right]);
                right++;
            }
        }
        while(left >= 0){
            ans[i++] = (nums[left]*nums[left]);
                left--;
        }
        
        while(right < n){
            ans[i++] = (nums[right]*nums[right]);
            right++;
        }
        return ans;
    }
};