class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int ele = nums[0];
        int count = 1;
        for(int i = 1; i<n; i++){
            if(nums[i] != ele){
                count--;
            }
            
            if(count == 0){
                ele = nums[i];
                count = 1;
            }else if(nums[i] == ele){
                count++;
            }
        }
        
        return ele;
    }
}