class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i=0; i<n; i++){
            int left = 0;
            int right = n-1;
            while(left < right){
                swap(image[i][left], image[i][right]);
                image[i][left] ^= 1;
                image[i][right] ^= 1;
                left++;
                right--;
            }
            
            // Handling middle element for odd n
            if(n & 1){
                image[i][left] ^= 1;
            }
        }
        return image;
    }
};