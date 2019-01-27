class Solution(object) :
    def minDeletionSize(self, a) :

        def isLexicographic(u, v) :
            for s in a :
                if s[v] < s[u] :
                    return False
            return True

        if not a or not a[0] :
            return 0
        n, m = len(a), len(a[0])
        g = [[] for _ in xrange(m + 1)]
        for u in xrange(m) :
            for v in xrange(u + 1, m) :
                if isLexicographic(u, v) :
                    g[u + 1].append(v + 1)
        for i in xrange(m) :
            g[0].append(i + 1)
        dis = [0 for _ in xrange(m + 1)]
        for u in xrange(m) :
            for v in g[u] :
                dis[v] = max(dis[v], dis[u] + 1)
        return m - max(dis)

