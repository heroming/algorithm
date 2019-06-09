class Solution(object) :
    def minSwap(self, s, t) :
        n = len(s)
        dp = [[n, n] for i in xrange(n)]
        dp[0][0] = 0
        dp[0][1] = 1
        for i in xrange(1, n) :
            a = s[i] > s[i - 1] and t[i] > t[i - 1]
            b = s[i] > t[i - 1] and t[i] > s[i - 1]
            if a and b :
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1])
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1
            elif a :
                dp[i][0] = dp[i - 1][0]
                dp[i][1] = dp[i - 1][1] + 1
            else :
                dp[i][0] = dp[i - 1][1]
                dp[i][1] = dp[i - 1][0] + 1
        return min(dp[n - 1][0], dp[n - 1][1])

