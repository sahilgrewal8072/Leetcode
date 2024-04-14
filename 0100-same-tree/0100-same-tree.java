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
    public void solve(TreeNode p, TreeNode q, boolean[] ans){
        if(ans[0] == false)return;
        if(p == null && q != null){
            ans[0] = false;
            return;
        }
        if(q == null && p != null){
            ans[0] = false;
            return;
        }
        if(p == null && q == null){
            return;
        }
        
        if(p.val != q.val){
            ans[0] = false;
            return;
        }
        
        solve(p.left, q.left, ans);
        solve(p.right, q.right, ans);
        return;
    }
    
    public boolean isSameTree(TreeNode p, TreeNode q) {
        boolean[] ans = {true};
        solve(p, q, ans);
        return ans[0];
    }
}