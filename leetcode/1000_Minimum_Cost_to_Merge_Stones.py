class Solution(object) :
    def mergeStones(self, S, K) :

        def dfs(k, w) :
            if k == K :
                self.ret.append(self.cord + [w])
            else :
                for x in self.valid :
                    if x + K - k <= w :
                        self.cord.append(x)
                        dfs(k + 1, w - x)
                        self.cord.pop()

        def generate(m) :
            if m == K :
                return [[1 for _ in xrange(K)]]
            self.ret = []
            self.valid = [1]
            while K - 1 + self.valid[-1] + K - 1 <= m :
                self.valid.append(self.valid[-1] + K - 1)
            self.cord = []
            dfs(1, m)
            return self.ret


        def solve(l, r) :
            if (l, r) not in self.dp :
                if r - l == 1 :
                    self.dp[(l, r)] = 0
                elif r - l == K :
                    self.dp[(l, r)] = sum(S[l:r])
                else :
                    m = r - l
                    if m not in self.situations :
                        self.situations[m] = generate(m)
                    ret = 0x66668888
                    for s in self.situations[m] :
                        k, w = l, 0
                        for t in s :
                            w += solve(k, k + t)
                            k += t
                        ret = min(ret, w)
                    self.dp[(l, r)] = ret + sum(S[l:r])

            return self.dp[(l, r)]

        n = len(S)
        if n == 1 :
            return 0
        if not (K == 2 or n % (K - 1) == 1) :
            return -1

        self.dp, self.situations = {}, {}
        self.crod, self.valid, self.ret = [], [], []

        return solve(0, n)

