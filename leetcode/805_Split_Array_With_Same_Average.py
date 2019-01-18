class Solution(object) :
    def splitArraySameAverage(self, v) :
        n, s = len(v), sum(v)
        if n < 2 :
            return False
        dp = [0 for _ in xrange(s + 1)]
        dp[0] = 1
        for x in v :
            for k in xrange(s, -1, -1) :
                if dp[k] :
                    dp[k + x] |= dp[k] << 1
        for a in xrange(1, n) :
            if s * a % n == 0 and (dp[s * a / n] >> a) & 1 :
                return True
        return False

