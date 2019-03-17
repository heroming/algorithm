class Solution(object) :
    def numDupDigitsAtMostN(self, n) :

        def dfs(s, k, bound) :

            if bound :

                ret, d = 0, self.bit[k]

                m = 0
                if k == 0 :
                    for i in xrange(d + 1) :
                        if s & (1 << i) :
                            m += 1
                    return m

                for i in xrange(d + 1) :
                    if s & (1 << i) :
                        if i == d :
                            ret += self.part[k - 1]
                        else :
                            ret += self.all[k - 1]
                    else :
                        if s == 0 and i == 0 :
                            ret += dfs(s, k - 1, False)
                        else :
                            ret += dfs(s | (1 << i), k - 1, i == d)

                return ret
            else :
                if self.dp[s][k] != -1 :
                    return self.dp[s][k];
                if k == 0 :
                    m, t = 0, s
                    while t > 0 :
                        m += t & 1
                        t >>= 1
                    self.dp[s][k] = m
                    return m

                ret, d = 0, self.N - 1
                for i in xrange(d + 1) :
                    if s & (1 << i) :
                        ret += self.all[k - 1]
                    else :
                        if s == 0 and i == 0 :
                            ret += dfs(s, k - 1, False)
                        else :
                            ret += dfs(s | (1 << i), k - 1, False)
                self.dp[s][k] = ret

                return ret

        e, p = n, 10
        self.bit, self.all, self.part = [], [], []
        while e > 0 :
            self.all.append(p)
            self.part.append(n % p + 1)
            self.bit.append(e % 10)
            e, p = e / 10, p * 10

        self.N, M = 10, len(self.bit)
        self.dp = [[-1 for _ in xrange(self.N)] for _ in xrange(1 << self.N)]

        return dfs(0, M - 1, True)

