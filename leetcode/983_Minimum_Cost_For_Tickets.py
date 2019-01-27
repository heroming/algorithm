class Solution(object) :
    def mincostTickets(self, days, costs) :

        inf = 0x666888
        duration = [1, 7, 30]
        dp = [[inf, inf, inf, inf] for _ in xrange(len(days))]
        dp[0] = [costs[0], costs[1], costs[2], inf]

        for k in xrange(1, len(days)) :
            # not by ticket
            idx = k - 1
            while idx >= 0 :
                for d in xrange(len(duration)) :
                    if days[k] < days[idx] + duration[d] and dp[idx][d] < dp[k][3] :
                        dp[k][3] = dp[idx][d]
                idx -= 1

            # by 1-day ticket
            dp[k][0] = min(dp[k - 1]) + costs[0]

            # by 7-day ticket
            dp[k][1] = min(dp[k - 1]) + costs[1]

            # by 30-day ticket
            dp[k][2] = min(dp[k - 1]) + costs[2]

        return min(dp[len(days) - 1])

