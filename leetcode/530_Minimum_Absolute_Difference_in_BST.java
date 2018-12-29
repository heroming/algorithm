/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int pre;
    private int ans;

    private void dfs(TreeNode node) {
        if (node == null) return;
        dfs(node.left);
        int diff = node.val - pre;
        if (diff >= 0 && diff < ans) {
            ans = diff;
        }
        pre = node.val;
        dfs(node.right);
    }

    public int getMinimumDifference(TreeNode root) {
        pre = ans = Integer.MAX_VALUE;
        dfs(root);
        return ans;
    }
}
