class Solution(object) :

    def minFallingPathSum(self, s):
        if not s or not s[0] :
            return 0
        n, m = len(s), len(s[0])
        dp = [[0 for _ in xrange(m)] for _ in xrange(2)]
        k = 0
        for i in xrange(n) :
            for j in xrange(m) :
                l = 0 if j == 0 else j - 1
                r = m if j == m - 1 else j + 2
                dp[k ^ 1][j] = min(dp[k][l:r]) + s[i][j]
            k ^= 1
        return min(dp[k])

