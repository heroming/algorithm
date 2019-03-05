# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoBST(self, root, x) :

        def findParent(node, x) :
            while node is not None :
                if node.val < x :
                    if node.right is None :
                        return node
                    node = node.right
                else :
                    if node.left is None :
                        return node
                    node = node.left
            return None

        if root is None :
            root = TreeNode(x)
        else :
            p = findParent(root, x)
            if p.val < x :
                p.right = TreeNode(x)
            else :
                p.left = TreeNode(x)
        return root

