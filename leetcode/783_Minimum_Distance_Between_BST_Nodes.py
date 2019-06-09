class Solution(object) :
    def minDiffInBST(self, root) :

        self.ans = sys.maxint
        self.pre = None
        self.dfs(root)

        return self.ans

    def dfs(self, node) :
        if node is None :
            return
        self.dfs(node.left)
        if self.pre is not None :
            self.ans = min(self.ans, node.val - self.pre)
        self.pre = node.val
        self.dfs(node.right)

