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
        se = sorted(list(set(s + [v << 1 for v in s])))
        dic = {v : k + 1 for (k, v) in enumerate(se)}
        bit = Bit(len(se) + 1)

        ans = 0
        for v in s[::-1] :
            ans += bit.query(dic[v] - 1)
            bit.update(dic[v << 1])
        return ans

