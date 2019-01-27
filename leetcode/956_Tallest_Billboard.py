class Solution(object) :
    def tallestBillboard(self, rods) :

        def dfs(k, m, t) :
            if t == 0 :
                return True
            if t < 0 or k >= len(choice) or m < 0 :
                return False
            for i in xrange(k, len(choice)) :
                if not (i > k and choice[i] == choice[i - 1]) and dfs(i + 1, m - 1, t - choice[i]) :
                    return True
            return False

        def solve(k, s, e) :
            m = len(choice)
            if e and m > 1 and (s & 1) == 0 and s > (ans[0] << 1) and dfs(0, (m - 2) >> 1, s >> 1) :
                ans[0] = (s >> 1)

            for i in xrange(k, -1, -1) :
                if not (i < k and rods[i] == rods[i + 1]) and sums[i] + s > (ans[0] << 1) :
                    choice.append(rods[i])
                    solve(i - 1, s + rods[i], True)
                    choice.pop()

        n = len(rods)
        if n <= 1 :
            return 0
        rods = sorted(rods)
        sums = [x for x in rods]
        for i in xrange(1, n) :
            sums[i] += sums[i - 1]
        ans, choice = [0], []
        solve(n - 1, 0, False)

        return ans[0]

