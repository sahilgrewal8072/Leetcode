class Solution {
public:
    bool binarySearch(int target, vector<int> arr){
        int low = 0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int r = 0;
        int c = col-1;
        while(c>=0 && r < row){
            
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] > target){
                c--;
            }else{
                r++;
            }
        }
        return false;
    }
};