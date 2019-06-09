class Solution(object) :
    def maxProfitAssignment(self, difficulty, profit, worker) :
        ans = 0
        idx = len(worker) - 1
        worker.sort()

        for p, d in sorted([(profit[i], difficulty[i]) for i in xrange(len(difficulty))], reverse=True) :
            while idx >= 0 and d <= worker[idx] :
                idx -= 1
                ans += p
                if idx < 0 :
                    return ans
        return ans

