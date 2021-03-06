#!/usr/bin/python
# -*- coding: utf-8 -*-

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


class Solution(object) :
    pass

class OneNode(object) :
    def __init__(self) :
        self.cnt = -1
        self.data = set([])
        self.pre = None
        self.nxt = None

class AllOne(object) :

    def __init__(self) :
        self.n = 0
        self.dic = {}
        self.head = OneNode()
        self.head.pre = self.head
        self.head.nxt = self.head

    def inc(self, key) :
        if key in self.dic :
            node = self.dic[key]
            if len(node.data) == 1 :
                if node.nxt.cnt == node.cnt + 1 :
                    node.nxt.data.add(key)
                    node.pre.nxt = node.nxt
                    node.nxt.pre = node.pre
                    self.dic[key] = node.nxt
                else :
                    node.cnt += 1
            else :
                node.data.remove(key)
                if node.nxt.cnt == node.cnt + 1 :
                    node.nxt.data.add(key)
                    self.dic[key] = node.nxt
                else :
                    no = OneNode()
                    no.cnt = node.cnt + 1
                    no.data.add(key)
                    no.nxt = node.nxt
                    no.pre = node
                    node.nxt.pre = no
                    node.nxt = no
                    self.dic[key] = no
        else :
            self.n += 1
            if self.head.nxt.cnt != 1 :
                no = OneNode()
                no.cnt = 1
                no.data.add(key)
                no.nxt = self.head.nxt
                no.pre = self.head
                self.head.nxt.pre = no
                self.head.nxt = no
                self.dic[key] = no
            else :
                self.head.nxt.data.add(key)
                self.dic[key] = self.head.nxt

    def dec(self, key):
        if key in self.dic :
            node = self.dic[key]
            if node.cnt == 1 :
                if len(node.data) == 1 :
                    node.pre.nxt = node.nxt
                    node.nxt.pre = node.pre
                else :
                    node.data.remove(key)
                self.n -= 1
                del self.dic[key]
            else :
                if len(node.data) == 1 :
                    if node.pre.cnt + 1 == node.cnt :
                        node.pre.data.add(key)
                        node.pre.nxt = node.nxt
                        node.nxt.pre = node.pre
                        self.dic[key] = node.pre
                    else :
                        node.cnt -= 1
                else :
                    node.data.remove(key)
                    if node.pre.cnt + 1 == node.cnt :
                        node.pre.data.add(key)
                        self.dic[key] = node.pre
                    else :
                        no = OneNode()
                        no.cnt = node.cnt - 1
                        no.data.add(key)
                        no.nxt = node
                        no.pre = node.pre
                        node.pre.nxt = no
                        node.pre = no
                        self.dic[key] = no

    def getMaxKey(self) :
        if self.n == 0 : return ""
        node = self.head.pre
        for x in node.data : return x

    def getMinKey(self) :
        if self.n == 0 : return ""
        node = self.head.nxt
        for x in node.data : return x

if __name__ == "__main__" :
    so = Solution()
    al = AllOne()
    al.inc('a')
    al.inc('b')
    al.inc('b')
    al.inc('c')
    al.inc('c')
    al.inc('c')
    al.dec('b')
    al.dec('b')
    print al.getMinKey()
    al.dec('a')
    print al.getMaxKey()
    print al.getMinKey()
 
