class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int &k) {
        int n = nums.size();
        int left = 0;
        deque<int> q;
        vector<int> ans;
        for(int i=0; i<n; i++){
            while(!q.empty() && q.back() < nums[i]){
                q.pop_back();
            }
            
            q.push_back(nums[i]);
            
            if((i - left) + 1 == k){
                ans.push_back(q.front());
            }
            
            if((i - left) + 1 == k){
                if(nums[left] == q.front())q.pop_front();
                left++;
            }
           
        }
        return ans;
    }
};