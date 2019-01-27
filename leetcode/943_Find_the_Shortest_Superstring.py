class Solution(object) :
    def shortestSuperstring(self, s) :
        def calculateDis(x, y) :
            if i == j :
                return len(s[x])
            m = min(len(s[x]), len(s[y]))
            return max([k if s[x][-k:] == s[y][:k] else 0 for k in xrange(1, m + 1)])

        if not s :
            return ""
        n = len(s)
        if n == 1 :
            return s[0]
        dis = [[0 for _ in xrange(n)] for _ in xrange(n)]
        for i in xrange(n) :
            for j in xrange(n) :
                dis[i][j] = calculateDis(i, j)
        inf = 0x10086
        dp = [[inf for _ in xrange(n)] for _ in xrange(1 << n)]
        path = [[-1 for _ in xrange(n)] for _ in xrange(1 << n)]
        bit = [0 for _ in xrange(1 << n)]
        for i in xrange(n) :
            dp[1 << i][i] = dis[i][i]
            bit[1 << i] = 1
        for k in xrange(1, n) :
            for e in xrange(1 << n) :
                if bit[e] != k :
                    continue
                for i in xrange(n) :
                    if (e & (1 << i)) == 0 :
                        continue
                    for j in xrange(n) :
                        if (e & (1 << j)) == 0 :
                            x = e | (1 << j)
                            w = dp[e][i] + len(s[j]) - dis[i][j]
                            if w < dp[x][j] :
                                dp[x][j] = w
                                path[x][j] = i
                            bit[x] = k + 1
        st = (1 << n) - 1
        l, k = inf, 0
        for i in xrange(n) :
            if dp[st][i] < l :
                l, k = dp[st][i], i

        order = [k]
        while path[st][k] != -1 :
            k = path[st][k]
            st ^= 1 << order[-1]
            order.append(k)

        ans = []
        for i in xrange(n - 1, -1, -1) :
            v = order[i]
            if i + 1 == n :
                ans.append(s[v])
            else :
                u = order[i + 1]
                ans.append(s[v][dis[u][v]:])
        return "".join(ans)

