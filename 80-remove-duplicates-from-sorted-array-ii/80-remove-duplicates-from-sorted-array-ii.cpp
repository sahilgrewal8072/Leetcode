class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // if( n < 2)return n;
        int itr = 0;
        int ex = 1;
        int count = 1;
        for(int itr = 0; itr < n-1; itr++){
            if(nums[itr] == nums[itr+1]){
                count++;
                if(count <= 2){
                    nums[ex] = nums[itr];
                    ex++;
                }
            }else{
                nums[ex] = nums[itr+1];
                count = 1;
                ex++;
            }
            
        }
        return ex;
    }
};