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
    
    # @param A: An integer list
    def __init__(self, A) :
        self.n = len(A)
        self.data = [0 for i in xrange(self.n + 1)]
        for k in xrange(self.n) :
            self.update(k + 1, A[k])
        
    def lowbit(self, x) :
        return x & (-x)
    
    def get(self, x) :
        ret = 0
        while x > 0 :
            ret += self.data[x]
            x -= self.lowbit(x)
        return ret
    
    def update(self, x, w) :
        while x <= self.n :
            self.data[x] += w
            x += self.lowbit(x)
    
    # @param start, end: Indices
    # @return: The sum from start to end
    def query(self, s, e) :
        return self.get(e + 1) - self.get(s)

    # @param index, value: modify A[index] to value.
    def modify(self, k, w):
        x = w - self.get(k + 1) + self.get(k)
        self.update(k + 1, x)
 
if __name__ == "__main__" :
    
    v = [6997,6794,5375,4057,5654,5566,5816,6153,4369,5207,2659,9291,9188,8350,9555,7796,7662,5849,9215,2096,2720,2788,3527,6994,1272,7857,7446,2937,7960,8751,9020,5997,2946,2466,9569,8268,7711,2236,3587,7152,9467,5455,7866,4276,3250,2840,2123,4897,5612,3005,7140,5945,1321,8850,6174,7406,4135,9586,8786,2669,4971,5437,5838,3277,8071,7034,4998,6000,1764,9318,7860,7599,2008,6887,4705,9013,4444,6651,2435,2533,4470,7504,5975,1700,7260,9648,3779,9672,7745,2692,2754,4441,7048,9180,3108,7872,7767,3714,8513,3653,1334,9855,3936,1357,1495,6775,8438,5234,2094,5254,2561,4373,7245,7461,5486,2380,7906,6735,5572,9638,4626,7446,1214,7523,1018,4120,4383,6436,2966,5350,3433,9389,2275,4819,6843,2173,5824,9176,9188,1343,5797,6061,7976,3024,3766,2379,7868,2951,4605,6464,6280,3060,7042,1325,3918,7511,9826,9260,7133,8459,6588,2033,6563,5477,9715,3199,2105,9154,9727,1697,5601,4438,1554,1228,2758,4939,7869,9823,6739,4962,1995,1491,7498,9682,6944,4854,5211,5622,8654,8450,8128,3984,7170,1607,3981,3575,6429,5911,7708,2288,9818,7029,8380,7283,7920,7075,3128,8220,2306,2805,4846,2268,8878,7313,3670,8283,4367,8096,3693,5642,6035,8752,8602,8753,3186,9691,3872,1962,2372,8715,3002,3252,8028,5927,9049,3894,5978,5055,9246,5851,4318,2208,2589,2116,8467,8537,6175,9293,6747,9367,8049,7487,3788,5625,6893,6149,1817,8516,9133,8048,7759,5165,3038,2447,5269,4682,8813,6393,6420,7055,1101,2040,5789,1988,5537,9180,2654,6269,2641,9844,6305,1688,8250,7568,7168,6293,8945,7434,2818,2285,2989,5301,7990,7350,9652,6803,7608,4397,6586,7515,6817,6064,9573,7757,3975,6374,3936,3611,6000,4141,5844,9657,4917,3943,7098,8821,6867,9114,5782,9010,1765,2650,7021,3977,6720,4508,9864,3448,7509,7649,6061,4620]
    so = Solution(v)

    so.modify(255,4606)
    so.modify(33,4085)
    so.modify(91,6006)
    so.modify(209,8613)
    so.modify(115,3538)
    so.modify(245,8621)
    print so.query(0,331)
    so.modify(114,4910)
    print so.query(2,331)
    so.modify(76,5102)
    print so.query(2,331)
    so.modify(73,9815)
    so.modify(159,7871)
    so.modify(248,7116)
    so.modify(82,5469)
    so.modify(205,5377)
    so.modify(15,3413)
    so.modify(307,5687)
    so.modify(324,5312)
    so.modify(140,1790)
    print so.query(1,331)
    so.modify(161,9475)
    so.modify(87,2109)
    so.modify(159,9304)
    so.modify(85,8227)
    so.modify(23,9747)
    print so.query(0,330)
    so.modify(10,9900)
    so.modify(160,2423)
    so.modify(272,7458)
    so.modify(24,3575)
    so.modify(30,1744)
    so.modify(43,5764)
