class Solution(object) :
    def isBipartite(self, g) :
        n = len(g)
        vis = [0 for i in xrange(n)]
        mark = [-1 for i in xrange(n)]

        finish = 0
        while finish < n :
            process = False
            for u in xrange(n) :
                if vis[u] == 1 :
                    vis[u] = 2
                    finish += 1
                    process = True
                    for v in g[u] :
                        if mark[v] == -1 :
                            mark[v] = mark[u] ^ 1
                            if vis[v] == 0 :
                                vis[v] = 1
                        elif (mark[u] ^ mark[v]) == 0 :
                            return False

            if finish < n and not process :
                for u in xrange(n) :
                    if vis[u] == 0 :
                        vis[u] = 1
                        mark[u] = 0
                        break

        return True

