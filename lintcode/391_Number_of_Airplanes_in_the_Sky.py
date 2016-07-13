#coding=utf-8
#!/usr/bin/python

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def show(self) :
        print self.val, 
        if self.next is not None :
            self.next.show()
        else :
            print

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class TreeLinkNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class UndirectedGraphNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []
        
class DirectedGraphNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class SegmentTreeNode:
    def __init__(self, start, end):
        self.start, self.end = start, end
        self.left, self.right = None, None

class TreeOrder(object):
    def preorder(self, root) :
        ans = []
        self.dfs(root, ans, 0)
        print ans
        
    def inorder(self, root) :
        ans = []
        self.dfs(root, ans, 1)
        print ans
        
    def postorder(self, root) :
        ans = []
        self.dfs(root, ans, 2)
        print ans
        
    def dfs(self, root, ans, flag) :
        if root == None : return
        if (flag == 0) : ans.append(root.val)
        self.dfs(root.left, ans, flag)
        if (flag == 1) : ans.append(root.val)
        self.dfs(root.right, ans, flag)
        if (flag == 2) : ans.append(root.val)
        
class Point(object):
    def __init__(self, a = 0, b = 0):
        self.x = a
        self.y = b
        
class Bit(object) :
    def __init__(self, n) :
        self.n = n
        self.data = [0 for _ in xrange(n + 1)]
        
    def lowbit(self, x) :
        return x & -x
    
    def update(self, k, w) :
        while k <= self.n :
            self.data[k] += w
            k += self.lowbit(k)
            
    def query(self, k) :
        ans = 0
        while k > 0 :
            ans += self.data[k]
            k -= self.lowbit(k)
        return ans
    
class Trie :
    
    N, X = 26, ord('a')
    
    def __init__(self) :
        self.count = 0
        self.word = None
        self.data = [None for i in xrange(Trie.N)]
        
    def insert_dfs(self, k, s) :
        
        self.count += 1
        if k == len(s) :
            self.word = s
            return
        
        idx = ord(s[k]) - Trie.X
        if self.data[idx] is None :
            self.data[idx] = Trie()
            
        self.data[idx].insert_dfs(k + 1, s)
        
    def delete_dfs(self, k, s) :
        
        self.count -= 1
        if k == len(s) :
            self.word = None
            return
        
        idx = ord(s[k]) - Trie.X
        if self.data[idx] :
            self.data[idx].delete_dfs(k + 1, s)
    
    def insert(self, s) :
        self.insert_dfs(0, s)
        
    def delete(self, s) :
        self.delete_dfs(0, s)
        
    def exist(self, idx) :
        return self.data[idx] is not None
    
    def get(self, idx) :
        return self.data[idx]
    
    def isWord(self) :
        return self.word is not None
            
class MaxHeap :
    
    def __init__(self) :
        self.data = []
        
    def size(self) :
        return len(self.data)
    
    def empty(self) :
        return self.size() == 0
    
    def top(self) :
        return None if self.empty() else self.data[0]
 
    def push(self, x) :
        k = self.size()
        self.data.append(x)
        while k > 0 :
            p = (k - 1) >> 1
            if self.data[k] <= self.data[p] : break
            self.data[k], self.data[p] = self.data[p], self.data[k]
            k = p
    
    def pop(self) :
        if self.empty() : return None
        x = self.data[0]
        self.data[0], self.data[-1] = self.data[-1], self.data[0]
        self.data.pop()
        k, n = 0, self.size()
        while k < n :
            idx = k
            l, r = (k << 1) | 1, (k + 1) << 1
            if l < n and self.data[idx] < self.data[l] : idx = l
            if r < n and self.data[idx] < self.data[r] : idx = r
            if idx == k : break
            self.data[idx], self.data[k] = self.data[k], self.data[idx]
            k = idx
        return x
                
class MinHeap :
    def __init__(self) :
        self.data = []
        
    def size(self) :
        return len(self.data)
    
    def empty(self) :
        return self.size() == 0
    
    def top(self) :
        return None if self.empty() else self.data[0]
 
    def push(self, x) :
        k = self.size()
        self.data.append(x)
        while k > 0 :
            p = (k - 1) >> 1
            if self.data[p] <= self.data[k] : break
            self.data[k], self.data[p] = self.data[p], self.data[k]
            k = p
    
    def pop(self) :
        if self.empty() : return None
        x = self.data[0]
        self.data[0], self.data[-1] = self.data[-1], self.data[0]
        self.data.pop()
        k, n = 0, self.size()
        while k < n :
            idx = k
            l, r = (k << 1) | 1, (k + 1) << 1
            if l < n and self.data[l] < self.data[idx] : idx = l
            if r < n and self.data[r] < self.data[idx] : idx = r
            if idx == k : break
            self.data[idx], self.data[k] = self.data[k], self.data[idx]
            k = idx
        return x

class TrieNode :
    N, X = 26, ord('a')
    
    def __init__(self) :
        self.count = 0
        self.word = False
        self.data = [None for i in xrange(TrieNode.N)]

class TrieTree :
    def __init__(self) :
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word) :
        
        def dfs(node, k) :
            if k == len(word) :
                node.word = True
                return
            idx = ord(word[k]) - TrieNode.X
            if not node.data[idx] :
                node.data[idx] = TrieNode()
            node.data[idx].count += 1
            dfs(node.data[idx], k + 1)
 
        if not word : return
        dfs(self.root, 0)
        

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word) :
 
        def dfs(node, k) :
            if k == len(word) :
                return node.word
            idx = ord(word[k]) - TrieNode.X
            if not node.data[idx] :
                return False
            return dfs(node.data[idx], k + 1)
        
        if not word : return True
        return dfs(self.root, 0)

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix) :
 
        def dfs(node, k) :
            if k == len(prefix) :
                return node.count > 0
            idx = ord(prefix[k]) - TrieNode.X
            if not node.data[idx] :
                return False
            return dfs(node.data[idx], k + 1)
 
        if not prefix : return True
        return dfs(self.root, 0)


class Solution:
    # @param airplanes, a list of Interval
    # @return an integer
    def countOfAirplanes(self, air) :
        if not air : return 0
        v = []
        for x in air :
            v.append((x.start, 1))
            v.append((x.end, 0))
        v.sort()
        ans, cnt = 0, 0
        for i in xrange(len(v)) :
            if v[i][1] == 1 :
                cnt += 1
                ans = max(ans, cnt)
            else :
                cnt -= 1
        return ans
 
            
if __name__ == "__main__" :
    so = Solution()
    print so.countOfAirplanes([[1,10],[2,3],[5,8],[4,7]])
