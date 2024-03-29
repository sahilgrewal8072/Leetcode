class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        
        for(int i = 0; i<n; i++){
            if(i != 0 && nums[i] == nums[i-1])continue;
            
            for(int j = i+1; j<n; j++){
                if(j > i+1 && nums[j] == nums[j-1])continue;
                
                int k = j+1;
                int z = n-1;
                while(k < z){
                    long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[z];
                    if(sum < target){
                        k++;
                    }else if(sum > target){
                        z--;
                    }else if(sum == target){
                        List<Integer> temp = Arrays.asList(nums[i], nums[j], nums[k], nums[z]);
                        ans.add(temp);
                        k++;
                        z--;
                        
                        
                        while(k < z && nums[k-1] == nums[k])k++;
                        while(k < z && nums[z+1] == nums[z])z--;
                    }
                }
            }
        }
        return ans;
    }
}