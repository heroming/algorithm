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


class Solution :
    # @param buildings: A list of lists of integers
    # @return: A list of lists of integers
    def buildingOutline(self, bu) :
        if not bu : return []
        
        n = len(bu)
        ans, dic = [], {}
        vis = [False for i in xrange(n)]
        
        # sort end points in x-axis order
        for k in xrange(n) :
            # start or end, building id, height
            if bu[k][0] not in dic :
                dic[bu[k][0]] = [(0, k, bu[k][2])]
            else :
                dic[bu[k][0]].append((0, k, bu[k][2]))
                
            if bu[k][1] not in dic :
                dic[bu[k][1]] = [(1, k, bu[k][2])]
            else :
                dic[bu[k][1]].append((1, k, bu[k][2]))
        
        heap = MaxHeap()
        start, height = None, None
        for key in sorted(dic.keys()) :
            point = dic[key]
            for x in point :
                if x[0] == 1 :
                    vis[x[1]] = True
                else :
                    heap.push((x[2], x[1]))
            while not heap.empty() and vis[heap.top()[1]] :
                heap.pop()
            if heap.empty() :
                ans.append([start, key, height])
                start, height = None, None
            else :
                h = heap.top()[0]
                if start is None :
                    start, height = key, h
                elif start < key and height != h :
                    ans.append([start, key, height])
                    start, height = key, h
        return ans


if __name__ == "__main__" :
    so = Solution()
    print so.buildingOutline([[1, 3, 3], [2, 4, 4], [5, 6, 1]])
    print so.buildingOutline([[2, 3, 2], [3, 4, 2]])
    print so.buildingOutline([[2, 3, 2], [1, 4, 1]])
    print so.buildingOutline([[2, 3, 2], [1, 4, 5]])
    print so.buildingOutline([[4,67,187],[3,80,65],[49,77,117],[67,74,9],[6,42,92],[48,67,69],[10,13,58],[47,99,152],[66,99,53],[66,71,34],[27,63,2],[35,81,116],[47,49,10],[68,97,175],[20,33,53],[24,94,20],[74,77,155],[39,98,144],[52,89,84],[13,65,222],[24,41,75],[16,24,142],[40,95,4],[6,56,188],[1,38,219],[19,79,149],[50,61,174],[4,25,14],[4,46,225],[12,32,215],[57,76,47],[11,30,179],[88,99,99],[2,19,228],[16,57,114],[31,69,58],[12,61,198],[70,88,131],[7,37,42],[5,48,211],[2,64,106],[49,73,204],[76,88,26],[58,61,215],[39,51,125],[13,38,48],[74,99,145],[4,12,8],[12,33,161],[61,95,190],[16,19,196],[3,84,8],[5,36,118],[82,87,40],[8,44,212],[15,70,222],[16,25,176],[9,100,74],[38,78,99],[23,77,43],[45,89,229],[7,84,163],[48,72,1],[31,88,123],[35,62,190],[21,29,41],[37,97,81],[7,49,78],[83,84,132],[33,61,27],[18,45,1],[52,64,4],[58,98,57],[14,22,1],[9,85,200],[50,76,147],[54,70,201],[5,55,97],[9,42,125],[31,88,146]])
