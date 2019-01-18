class Solution(object) :
    def deleteAndEarn(self, v) :
        if not v :
            return 0

        # count 
        w = [0 for i in xrange(max(v) + 1)]
        for x in v :
            w[x] += 1

        # 0 for not delete, 1 for delete
        dp = [[0, 0] for i in xrange(len(w))]

        ans = 0
        for k in xrange(1, len(w)) :
            dp[k][0] = max(dp[k - 1][0], dp[k - 1][1])
            dp[k][1] = dp[k - 1][0] + w[k] * k
            ans = max(ans, dp[k][1])
        return ans

