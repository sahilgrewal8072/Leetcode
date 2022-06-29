class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        int ans = 0;
        unordered_set<string> st;
        for(int i=0; i<n; i++){   
            for(int j=i; j<n; j++){
                string temp = "";
                 int count = 0;
               for(int k=i; k<=j; k++){
                   if(nums[k]%p == 0){
                       count++;
                   } 
                   
                   temp.push_back(nums[k] + '0');
               }
                if(count <= k){
                    st.insert(temp);
                }
            }
            
        }
        return st.size();
    }
};