class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int l = 0;
        int r = n-1;
        int leftmax = INT_MIN;
        int rightmax = INT_MIN;
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] <= leftmax){
                    water += leftmax - height[l];
                }else{
                    leftmax = height[l];
                }
                l++;
            }else{
                if(height[l] >= height[r]){
                    if(height[r] <= rightmax){
                        water += rightmax - height[r];
                    }else{
                        rightmax = height[r];
                    }
                    r--;
                }
            }
        }
        return water;
    }
};