class Solution(object):
    def networkDelayTime(self, times, n, m) :
        inf = 0x888888
        dis = [inf for i in xrange(n + 1)]
        g = [[] for i in xrange(n + 1)]
        for (u, v, w) in times :
            g[u].append((v, w))
        front, que = 0, []
        inq = [False for i in xrange(n + 1)]
        dis[0] = dis[m] = 0
        inq[m] = True
        que.append(m)

        while front < len(que) :
            u = que[front]
            inq[u] = False
            front += 1
            for (v, w) in g[u] :
                if dis[u] + w < dis[v] :
                    dis[v] = dis[u] + w
                    if not inq[v] :
                        inq[v] = True
                        que.append(v)
        ans = max(dis)
        if ans == inf :
            return -1
        return ans

