class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        List<Integer> ans = new ArrayList<Integer>();
        int e1 = Integer.MIN_VALUE;
        int e2 = Integer.MIN_VALUE;
        int c1 = 0;
        int c2 = 0;
        int mini = n/3;
        // System.out.println(mini);
        for(int i = 0; i<n; i++){
            if(c1 == 0 && nums[i] != e2){
                c1 = 1;
                e1 = nums[i];
            }else if(c2 == 0 && nums[i] != e1){
                c2 = 1;
                e2 = nums[i];
            }else if(nums[i] == e1){
                c1++;
            }else if(nums[i] == e2){
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        
         c1 = 0;
         c2 = 0;
        for(int i= 0; i<n; i++){
            if(e1 == nums[i])c1++;
            if(e2 == nums[i])c2++;
        }
        if(c1 > mini)
        ans.add(e1);
        if(c2 > mini)
        ans.add(e2);
        return ans;
    }
}