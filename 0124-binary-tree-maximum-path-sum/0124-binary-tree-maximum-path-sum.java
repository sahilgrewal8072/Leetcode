/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int solve(TreeNode root, int[] maxi){
        if(root == null)return 0;
        
        int left_sum  =  Math.max(0, solve(root.left, maxi));
        int right_sum = Math.max(0, solve(root.right, maxi));
        
        maxi[0] = Math.max(maxi[0], root.val + left_sum + right_sum);
        
        return Math.max(left_sum, right_sum) + root.val;
    }
    public int maxPathSum(TreeNode root) {
        int[] maxi = {Integer.MIN_VALUE};
        solve(root, maxi);
        return maxi[0];
    }
}