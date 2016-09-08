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

from random import randint
class RandomizedSet(object):

    def __init__(self):
        self.dic = {}
        self.data = []

    def insert(self, w):
        if w in self.dic : return False
        n = len(self.data)
        self.data.append(w)
        if n == 0 :
            self.dic[w] = 0
        else :
            k = randint(0, n) 
            self.dic[w] = k
            self.dic[self.data[k]] = n
            self.data[k], self.data[n] = self.data[n], self.data[k]
        return True

    def remove(self, w):
        if w not in self.dic : return False
        k = self.dic[w]
        del self.dic[w]
 
        if self.data[-1] != w :
            self.dic[self.data[-1]] = k
            self.data[k], self.data[-1] = self.data[-1], self.data[k]
        self.data.pop()
        n = len(self.data) - 1
        if n >= 0 :
            k = randint(0, n)
            self.dic[self.data[k]] = n
            self.dic[self.data[n]] = k
            self.data[k], self.data[n] = self.data[n], self.data[k]
        return True

    def getRandom(self):
        if not self.data : return None
        n = len(self.data) - 1
        k = randint(0, n)
        self.dic[self.data[k]] = n
        self.dic[self.data[n]] = k
        self.data[k], self.data[n] = self.data[n], self.data[k]
        return self.data[n]

if __name__ == '__main__' :
    
    so = Solution()
