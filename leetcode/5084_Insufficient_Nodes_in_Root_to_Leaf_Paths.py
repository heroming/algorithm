class Solution(object) :
    def sufficientSubset(self, root, limit) :

        def dfs(node, pre) :
            if node is None :
                return 0
            weight = pre + node.val
            l = dfs(node.left, weight)
            r = dfs(node.right, weight)
            if weight + l < limit :
                node.left = None
            if weight + r < limit :
                node.right = None
            return node.val + max(l, r)

        s = dfs(root, 0)
        if s < limit :
            return None
        return root

