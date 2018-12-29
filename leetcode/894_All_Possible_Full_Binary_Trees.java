class Solution {
    public List<TreeNode> allPossibleFBT(int n) {
        if ((n & 1) == 0) {
            return new ArrayList<>();
        }
        List<List<TreeNode>> lists = new ArrayList<>();
        for (int k = 1; k <= n; k += 2) {
            List<TreeNode> list = new ArrayList<>();
            if (k == 1) {
                list.add(new TreeNode(0));
            } else {
                for (int l = 1; l < k; l += 2) {
                    int r = k - l - 1;
                    for (TreeNode left : lists.get(l >> 1)) {
                        for (TreeNode right : lists.get(r >> 1)) {
                            TreeNode node = new TreeNode(0);
                            node.left = left;
                            node.right = right;
                            list.add(node);
                        }
                    }
                }
            }
            lists.add(list);
        }
        return lists.get(n >> 1);
    }
}
