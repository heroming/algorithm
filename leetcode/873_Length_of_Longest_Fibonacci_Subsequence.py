class Solution(object) :
    def lenLongestFibSubseq(self, s):

        ans, n, se = 0, len(s), set(s)
        for i in xrange(n) :
            for j in xrange(i + 1, n) :
                m, a, b = 2, s[i], s[j]
                while a + b in se :
                    a, b, m = b, a + b, m + 1
                ans = max(ans, m)
        return ans if ans > 2 else 0

