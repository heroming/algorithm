class Solution(object) :

    def knightDialer(self, N) :
        mod = long(1e9 + 7)
        move = [(4, 6), (6, 8), (7, 9), (4, 8), (0, 3, 9), (), (0, 1, 7), (2, 6), (1, 3), (2, 4)]
        dp = [[x for _ in range(10)] for x in xrange(2)]
        for k in xrange(1, N) :
            for u in xrange(len(move)) :
                for v in move[u] :
                    dp[0][v] += dp[1][u]
            for i in xrange(len(dp[0])) :
                dp[1][i] = dp[0][i] % mod
                dp[0][i] = 0
        return sum(dp[1]) % mod

