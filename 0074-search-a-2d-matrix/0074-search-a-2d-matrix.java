class Solution {
    public static boolean binary_search(int[] matrix, int n, int target){
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(matrix[mid] == target)return true;
            else if(matrix[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;
    }
    public boolean searchMatrix(int[][] matrix, int target) {
        int row_size = matrix.length;
        int col_size = matrix[0].length;
        int top = 0;
        int bottom = row_size - 1;
        int mid;
        while(top <= bottom){
            mid = (top + bottom) >> 1;
            if(matrix[mid][0] <= target && matrix[mid][col_size - 1] >= target){
                return binary_search(matrix[mid], col_size, target);
            }else if(matrix[mid][0] > target){
                bottom = mid - 1;
            }else{
                top = mid  + 1;
            }
        }
        return false;
    }
}