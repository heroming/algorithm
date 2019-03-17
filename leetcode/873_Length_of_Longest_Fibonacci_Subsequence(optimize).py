class Solution(object) :
    def lenLongestFibSubseq(self, s):

        n = len(s)
        dp = collections.defaultdict(lambda: 2)
        idx = {s[0] : 0}
        for i in xrange(1, n - 1) :
            idx[s[i]] = i
            for j in xrange(i + 1, n) :
                x = s[j] - s[i]
                if x >= s[i] :
                    break
                elif x in idx :
                    dp[(i, j)] = dp[idx[x], i] + 1
        if not dp :
            return 0
        return max(dp.values())

