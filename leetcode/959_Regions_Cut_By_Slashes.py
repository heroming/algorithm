class Solution(object) :
    def regionsBySlashes(self, grid) :

        n = len(grid)
        m = (n * n) << 2
        g = [[] for _ in xrange(m)]
        s = [True] * m

        def dfs(u) :
            s[u] = False
            for v in g[u] :
                if s[v] :
                    dfs(v)

        # build graph
        for i in xrange(n) :
            for j in xrange(n) :
                k = i * n + j
                if i > 0 :
                    g[k << 2].append((k - n) << 2 | 2)
                if i + 1 < n :
                    g[k << 2 | 2].append((k + n) << 2)
                if j > 0 :
                    g[k << 2 | 1].append((k - 1) << 2 | 3)
                if j + 1 < n :
                    g[k << 2 | 3].append((k + 1) << 2 | 1)

                if grid[i][j] == ' ' :
                    g[k << 2].append(k << 2 | 1)
                    g[k << 2].append(k << 2 | 3)
                    g[k << 2 | 1].append(k << 2)
                    g[k << 2 | 1].append(k << 2 | 2)
                    g[k << 2 | 2].append(k << 2 | 1)
                    g[k << 2 | 2].append(k << 2 | 3)
                    g[k << 2 | 3].append(k << 2 | 2)
                    g[k << 2 | 3].append(k << 2)
                elif grid[i][j] == '/' :
                    g[k << 2].append(k << 2 | 1)
                    g[k << 2 | 1].append(k << 2)
                    g[k << 2 | 2].append(k << 2 | 3)
                    g[k << 2 | 3].append(k << 2 | 2)
                else :
                    g[k << 2].append(k << 2 | 3)
                    g[k << 2 | 3].append(k << 2)
                    g[k << 2 | 1].append(k << 2 | 2)
                    g[k << 2 | 2].append(k << 2 | 1)

        # get regions
        ans = 0
        for i in xrange(m) :
            if s[i] :
                ans += 1
                dfs(i)

        return ans

