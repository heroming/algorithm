class TreeNode(object):
	def __init__(self, x):
    	self.val = x
        self.left = None
        self.right = None

class Solution(object) :
    def smallestFromLeaf(self, root) :

        self.a = ord('a')
        self.s = []
        self.ans = None

        def dfs(node) :
            self.s.append(chr(self.a + node.val))
            if node.left is None and node.right is None :
                x = ''.join(self.s[::-1])
                if self.ans is None or x < self.ans :
                    self.ans = x
            else :
                if node.left is not None :
                    dfs(node.left)
                if node.right is not None :
                    dfs(node.right)
            self.s.pop()

        dfs(root)
        return self.ans

