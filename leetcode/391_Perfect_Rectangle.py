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

class ScanNode(object) :
    def __init__(self) :
        self.cnt = 0
        self.ret = 0
 
class ScanLine(object) :
    def __init__(self, n, disc) :
        self.disc = disc
        self.data = [ScanNode() for _ in xrange(n << 2)]
 
    def update(self, v, s, e, a, b, w) :
        if a <= s and e <= b :
            self.data[v].cnt += w
            self.down(v, s, e)
            return
        m = (s + e) >> 1
        if a <= m :
            self.update(v << 1, s, m, a, b, w)
        if m < b :
            self.update(v << 1 | 1, m + 1, e, a, b, w)
        self.down(v, s, e)
 
    def down(self, v, s, e) :
        if self.data[v].cnt :
            self.data[v].ret = self.disc[e] - self.disc[s - 1]
            return
        if s == e :
            self.data[v].ret = 0
        else :
            self.data[v].ret = self.data[v << 1].ret + self.data[v << 1 | 1].ret
 
class Solution(object) :
 
    def isRectangleCover(self, rect) :
        if not rect : return False
        segs, disc, dic = [], [], {}
        area, bounder = 0, rect[0][:]
        for rec in rect :
            disc.append(rec[1])
            disc.append(rec[3])
            if rec[0] < bounder[0] :
                bounder[0], bounder[1] = rec[0], rec[1]
            elif rec[0] == bounder[0] :
                bounder[1] = min(bounder[1], rec[1])
            if bounder[2] < rec[2] :
                bounder[2], bounder[3] = rec[2], rec[3]
            elif bounder[2] == rec[2] :
                bounder[3] = max(bounder[3], rec[3])
            area += (rec[2] - rec[0]) * (rec[3] - rec[1])
        rect_area = (bounder[2] - bounder[0]) * (bounder[3] - bounder[1])
        if area != rect_area : return False
 
        print "----------------------"
        disc = sorted(list(set(disc)))
        for i in xrange(len(disc)) : dic[disc[i]] = i + 1

        for rec in rect :
            segs.append((rec[0], 1, dic[rec[1]], dic[rec[3]]))
            segs.append((rec[2], -1, dic[rec[1]], dic[rec[3]]))
        segs.sort()
        
        n = len(dic)
        rect_area = 0
        scan = ScanLine(n, disc)
        scan.update(1, 1, n, segs[0][2], segs[0][3] - 1, segs[0][1])
        for k in xrange(1, len(segs)) :
            rect_area += scan.data[1].ret * (segs[k][0] - segs[k - 1][0])
            scan.update(1, 1, n, segs[k][2], segs[k][3] - 1, segs[k][1])
        
        return rect_area == area
 
if __name__ == '__main__' :
    so = Solution()
    rects = [[1,1,3,3]]
    print so.isRectangleCover(rects)

    rects = [[10,100,30,300],[30,100,40,200],[30,200,40,400],[10,300,20,400],[20,300,30,400]]
    print so.isRectangleCover(rects)

    rects = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
    print so.isRectangleCover(rects)

    rects = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
    print so.isRectangleCover(rects)
    
    rects =  [[1,1,3,3],[3,1,5,2],[1,3,2,4],[3,2,4,4]]
    print so.isRectangleCover(rects)
    
    rects = [[1,1,3,3],[3,1,4,2],[2,2,4,4]]
    print so.isRectangleCover(rects)
    
