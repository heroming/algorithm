#!/usr/bin/env python
# -*- coding: utf-8 -*-

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
    def show(self) :
        it, v = self, []
        while it :
            v.append(it.val)
            it = it.next
        print v
    
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class TreeOrder(object):
    def preorder(self, root) :
        ans = []
        self.dfs(root, ans, 0)
        print ans
        
    def inorder(self, root) :
        ans = []
        self.dfs(root, ans, 1)
        print ans
        
    def postoder(self, root) :
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
        
class TrieNode(object) :
    n = 26
    def __init__(self) :
        self.finish = False
        self.data = [None for i in range(self.n)]
        
class MinHeap(object) :
    
    def __init__(self) :
        self.data = []
        
    def heapify(self, k) :
        while True :
            idx = k
            l, r = (k << 1) | 1, (k + 1) << 1
            if l < len(self.data) and self.data[l] < self.data[idx] : idx = l
            if r < len(self.data) and self.data[r] < self.data[idx] : idx = r
            if idx == k : break
            self.data[k], self.data[idx] = self.data[idx], self.data[k]
            k = idx
            
    def push(self, x) :
        k = len(self.data)
        self.data.append(x)
        while k > 0 :
            p = (k - 1) >> 1
            if self.data[p] <= self.data[k] : break
            self.data[p], self.data[k] = self.data[k], self.data[p]
            k = p
    
    def top(self) :
        if not self.data : return None
        return self.data[0]
    
    def pop(self) :
        if not self.data : return None
        ret = self.data[0]
        self.data[0] = self.data[-1]
        self.data.pop()
        self.heapify(0)
        return ret
    
    def size() :
        return len(self.data)
    
    def isEmpty(self) :
        return len(self.data) == 0
 

class Solution(object) :
    
    def kSmallestPairs(self, a, b, t) :
        
        def find(v, w) :
            l, r = 0, len(v) - 1
            while l <= r :
                mi = (l + r) >> 1
                if v[mi] <= w :
                    l = mi + 1
                else :
                    r = mi - 1
            return l
        
        ans = []
        n, m = len(a), len(b)
        if n * m <= t :
            ans = [[x, y] for x in a for y in b]
        else :
            l, r = a[0] + b[0], a[-1] + b[-1]
            while l <= r :
                mi = (l + r) >> 1
                count = 0
                if n <= m :
                    for k in xrange(n) :
                        w = find(b, mi - a[k])
                        count += w
                        if w == 0 or t <= count : break
                else :
                    for k in xrange(m) :
                        w = find(a, mi - b[k])
                        count += w
                        if w == 0 or t <= count : break
                if count < t :
                    l = mi + 1
                else :
                    r = mi - 1
            total = l
            if n <= m :
                for k in xrange(n) :
                    w = find(b, total - a[k])
                    for i in xrange(w) :
                        ans.append([a[k], b[i]])
            else :
                for k in xrange(m) :
                    w = find(a, total - b[k])
                    for i in xrange(w) :
                        ans.append([a[i], b[k]])
        ans.sort(lambda x, y : cmp((x[0] + x[1], x[0], x[1]), (y[0] + y[1], y[0], y[1])))
        return ans[:t]

if __name__ == '__main__' :
    
    so = Solution()
