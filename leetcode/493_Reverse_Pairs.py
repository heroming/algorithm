class Bit(object) :
    def __init__(self, n) :
        self.n = n
        self.data = [0 for _ in xrange(n + 1)]

    def lowbit(self, x) :
        return x & -x

    def update(self, k) :
        while k <= self.n :
            self.data[k] += 1
            k += self.lowbit(k)

    def query(self, k) :
        ans = 0
        k = min(k, self.n)
        while k > 0 :
            ans += self.data[k]
            k -= self.lowbit(k)
        return ans

class Solution(object) :
    def reversePairs(self, s) :
        n = len(s)
        if n <= 1 : return 0

        idx = sorted([(v, k + 1) for (k, v) in enumerate(s)])
        bit = Bit(n + 1)
        it, cnt, ans = 0, 0, 0
        for k in xrange(n) :
            while it < n and (idx[it][0] << 1) < idx[k][0] :
                bit.update(idx[it][1])
                it += 1
                cnt += 1
            ans += cnt - bit.query(idx[k][1])
        return ans

