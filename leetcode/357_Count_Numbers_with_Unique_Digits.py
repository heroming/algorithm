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
 
    def countNumbersWithUniqueDigits(self, n) :
        dp = [0L for i in xrange(10)]
        dp[1] = 10
        dp[2] = 9 * 9
        for k in xrange(3, 10) :
            dp[k] = dp[k - 1] * (10 - k + 1)
        for k in xrange(1, 10) :
            dp[k] += dp[k - 1]
        dp[0] = 1
        if n < 10 : return dp[n]
        return dp[9]

if __name__ == '__main__' :
    
    so = Solution()
