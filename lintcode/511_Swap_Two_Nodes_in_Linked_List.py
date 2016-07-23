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
        k = min(k, self.n)
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
            if word[k] == '.' :
                for no in node.data :
                    if no is not None and dfs(no, k + 1) :
                        return True
                return False
            else :
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


class SegmentTree :
    
    def __init__(self, v, s = "MIN") :
        self.n = len(v)
        self.status = s
        self.data = [0 for i in xrange(self.n << 2)]
        self.build(1, 1, self.n, v)
        
    def build(self, x, s, e, v) :
        if s == e :
            if self.status == "MIN" or self.status == "MAX" or self.status == "SUM" :
                self.data[x] = v[s - 1]
            return
        m = (s + e) >> 1
        self.build(x << 1, s, m, v)
        self.build(x << 1 | 1, m + 1, e, v)
        if self.status == "MIN" :
            self.data[x] = min(self.data[x << 1], self.data[x << 1 | 1])
        elif self.status == "MAX" :
            self.data[x] = max(self.data[x << 1], self.data[x << 1 | 1])
        elif self.status == "SUM" :
            self.data[x] = self.data[x << 1] + self.data[x << 1 | 1]
        
    def query(self, l, r) :
        l, r = max(1, l), min(self.n, r)
        if r < l : return None
        return self.query_dfs(1, 1, self.n, l, r)
    
    def query_dfs(self, x, l, r, s, e) :
        if s <= l and r <= e :
            return self.data[x]
        m = (l + r) >> 1
        if e <= m : return self.query_dfs(x << 1, l, m, s, e)
        if m < s : return self.query_dfs(x << 1 | 1, m + 1, r, s, e)
        a = self.query_dfs(x << 1, l, m, s, e)
        b = self.query_dfs(x << 1 | 1, m + 1, r, s, e)
        if self.status == "MIN" :
            return min(a, b)
        elif self.status == "MAX" :
            return max(a, b)
        elif self.status == "SUM" :
            return a + b

class Solution :
    # @param {ListNode} head, a ListNode
    # @oaram {int} v1 an integer
    # @param {int} v2 an integer
    # @return {ListNode} a new head of singly-linked list
    def swapNodes(self, head, v1, v2) :
        
        # for invalid situation
        if head is None or v1 == v2 : return head
        
        # the parent of v1 and v2
        p1, p2 = None, None
        it = head
        while it :
            if it.val == v1 : break
            it, p1 = it.next, it
        it = head
        while it :
            if it.val == v2 : break
            it, p2 = it.next, it
        if (p1 and p1.next is None) or (p2 and p2.next is None) :
            return head
        
        # if v1 or v2 is head
        if p1 is None or p2 is None :
            if p2 is None :
                p1, p2 = p2, p1
            if p2 == head :
                vx = head
                vy = vx.next
                ty = vy.next
                
                vy.next = vx
                vx.next = ty
                head = vy
            else :
                vx = head
                tx = vx.next
                vy = p2.next
                ty = vy.next
                
                vy.next = tx
                p2.next = vx
                vx.next = ty
                head = vy
        else :
            # for p1 and p2 are directly linked
            if p2.next == p1 :
                p1, p2 = p2, p1
            if p1.next == p2 :
                vx = p2
                vy = vx.next
                ty = vy.next
                p1.next = vy
                vy.next = vx
                vx.next = ty
     
            # for common situation
            else :
                vx = p1.next
                vy = p2.next
                tx = vx.next
                ty = vy.next
                p1.next = vy
                vy.next = tx 
                p2.next = vx
                vx.next = ty
        return head
            
 
if __name__ == "__main__" :
    so = Solution()
    l1 = ListNode(1)
    l2 = ListNode(2)
    l3 = ListNode(3)
    l4 = ListNode(4)
    l1.next = l2
    l2.next = l3
    l3.next = l4
    l1.show()
    h = so.swapNodes(l1, 2, 3)
    h.show()
 
