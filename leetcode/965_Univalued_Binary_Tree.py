class Solution(object) :

    def isUnivalTree(self, root):
        if not root :
            return True
        self.value = root.val
        return self.dfs(root)

    def dfs(self, node) :
        if not node :
            return True
        if node.val != self.value :
            return False
        return self.dfs(node.left) and self.dfs(node.right)

