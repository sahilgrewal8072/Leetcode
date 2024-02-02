class Solution {
    public boolean binarySearch(int target, int[] matrix, int n){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(matrix[mid] == target){
                return true;
            }else if(matrix[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
    
    public boolean searchMatrix(int[][] matrix, int target) {
        int row_size = matrix.length;
        int col_size = matrix[0].length;
        int left_iterator = col_size - 1;
        int bottom_iterator = 0;
        boolean ans = false;
        for(int i=0; i<row_size; i++){
            if(matrix[i][0] <= target && matrix[i][col_size-1] >= target){
                 ans = binarySearch(target, matrix[i], col_size);
                if(ans)return ans;
            }
        }
        // while(bottom_iterator < row_size && left_iterator >= 0){
        //     if(matrix[bottom_iterator][left_iterator] == target)return true;
        //     else if(matrix[bottom_iterator][left_iterator] > target)left_iterator--;
        //     else
        //     bottom_iterator++;
        // }
        return ans;
    }
}