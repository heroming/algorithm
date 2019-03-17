class Solution(object) :
    def numPairsDivisibleBy60(self, time) :
        N, n = 60, len(time)
        mod = [[] for _ in xrange(N)]

        ans = 0
        for i in xrange(n) :
            k = time[i] % N
            x = (N - k) % N
            ans += len(mod[x])

            mod[k].append(i)
        return ans

