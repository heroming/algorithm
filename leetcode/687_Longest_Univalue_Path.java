class Solution {
    private int ans = 0;

    public int longestUnivaluePath(TreeNode root) {
        if (root == null) return 0;
        ans = 0;
        dfs(root);
        return ans - 1;
    }

    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int l = dfs(node.left);
        int r = dfs(node.right);
        int ret = 1, link = 1;
        if (l > 0 && node.left.val == node.val) {
            ret += l;
            link += l;
        }
        if (r > 0 && node.right.val == node.val) {
            ret += r;
            link = Math.max(link, r + 1);
        }
        ans = Math.max(ans, ret);
        return link;
    }
}
