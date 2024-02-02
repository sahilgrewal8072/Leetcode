class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row_size = matrix.length;
        int col_size = matrix[0].length;
        int left_iterator = col_size - 1;
        int bottom_iterator = 0;
        while(bottom_iterator < row_size && left_iterator >= 0){
            if(matrix[bottom_iterator][left_iterator] == target)return true;
            else if(matrix[bottom_iterator][left_iterator] > target)left_iterator--;
            else
            bottom_iterator++;
        }
        return false;
    }
}