class Solution(object) :

    def tallestBillboard(self, rods) :

        def solve(s) :
            dp = collections.defaultdict(int)
            dp[0] = 0
            for x in s :
                for (y, w) in dp.items() :
                    dp[y + x] = max(dp[y + x], w)
                    e = abs(y - x)
                    dp[e] = max(dp[e], w + min(x, y))
            return dp


        n = len(rods)
        if n <= 1 :
            return 0
        m = n >> 1
        l, r = solve(rods[:m]), solve(rods[m:])
        return max(l[x] + r[x] + x for x in l if x in r)

