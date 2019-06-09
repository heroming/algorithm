class Solution(object) :
    def maxSubarraySumCircular(self, v) :
        s, ans = 0, v[0]
        for x in v :
            s += x
            if ans < s :
                ans = s
            if s < 0 :
                s = 0
        s, u = 0, v[:] + [0]
        for i in xrange(len(v) - 1, -1, -1) :
            s += v[i]
            u[i] = max(s, u[i + 1])
        s = 0
        for i in xrange(len(v)) :
            s += v[i]
            ans = max(ans, s + u[i + 1])
        return ans

