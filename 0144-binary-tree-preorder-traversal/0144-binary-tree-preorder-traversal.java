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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null)return ans;
        Stack<TreeNode> st = new Stack<>();
        while(st.size() > 0 || root != null){
            if(root != null){
                ans.add(root.val);
                st.push(root);
                root = root.left;
            }else if(root == null){
                root = st.peek();
                st.pop();
                root = root.right;
            }
        }
        return ans;
    }
}