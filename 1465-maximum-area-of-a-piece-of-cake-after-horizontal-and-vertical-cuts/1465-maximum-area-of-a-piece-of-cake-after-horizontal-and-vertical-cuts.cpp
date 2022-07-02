class Solution {
public:
    int M = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
       
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
         int mx_height = horizontalCuts[0];
        if(n == 1){
            mx_height = max(h - horizontalCuts[n-1], horizontalCuts[0]);
        }
        int mx_width = verticalCuts[0];
        if(m == 1){
            mx_width = max(w - verticalCuts[m-1], verticalCuts[0]);
        }
        
        for(int i=1; i<n; i++){
            if(horizontalCuts[i] - horizontalCuts[i-1] > mx_height){
                mx_height = horizontalCuts[i] - horizontalCuts[i-1];
            }
        }
        
         for(int i=1; i<m; i++){
            if(verticalCuts[i] - verticalCuts[i-1] > mx_width){
                mx_width = verticalCuts[i] - verticalCuts[i-1];
            }
        }
        mx_height = max({mx_height, h - horizontalCuts[n-1], horizontalCuts[0]});
         mx_width = max({mx_width, w - verticalCuts[m-1], verticalCuts[0]});
        return (1ll*mx_height*mx_width)%M;
    }
};