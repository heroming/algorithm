class Solution(object) :
    def sumRootToLeaf(self, root) :

        def isLeaf(node) :
            return node.left is None and node.right is None

        def dfs(node, s) :
            if node is None :
                return
            x = (s << 1) | node.val
            if isLeaf(node) :
                self.ans += x
                return
            dfs(node.left, x)
            dfs(node.right, x)

        self.ans = 0
        dfs(root, 0)

        return self.ans

