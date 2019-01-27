class Solution(object) :
    def countTriplets(self, u) :
        cnt = [0 for _ in xrange(1 << 16)]
        for i in xrange(1, len(u)) :
            for j in xrange(i) :
                cnt[u[i] & u[j]] += 2
        ans = cnt[0]
        for x in u :
            if x == 0 :
                ans += 1
            for s in xrange(1 << 16) :
                if (x & s) == 0 :
                    ans += cnt[s]
        return ans

