class Solution(object) :
    def verticalTraversal(self, root) :

        def dfs(node, x, y) :
            if node is None :
                return
            if x in self.dic :
                self.dic[x].append((y, node.val))
            else :
                self.dic[x] = [(y, node.val)]
            dfs(node.left, x - 1, y + 1)
            dfs(node.right, x + 1, y + 1)

        self.dic = {}
        dfs(root, 0, 0)
        ans = []
        for key in sorted(self.dic.keys()) :
            value = sorted(self.dic[key])
            ans.append([w for (_, w) in value])
        return ans

