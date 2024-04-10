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
    public int len_preorder(TreeNode root){
        if(root == null){
            return 0;
        }
        
        return Math.max(1 + len_preorder(root.left), 1 + len_preorder(root.right));
    }
    
    public int maxDepth(TreeNode root) {
        return len_preorder(root);
    }
}