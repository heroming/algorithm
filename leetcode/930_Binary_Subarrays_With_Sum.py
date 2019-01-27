class Solution(object) :
    def numSubarraysWithSum(self, s, t) :

        def calc(n) :
            return n * (n - 1) >> 1

        one = [i for i in xrange(len(s)) if s[i] == 1]
        ans = 0
        if t == 0 :
            if one :
                ans += calc(one[0] + 1)
                ans += calc(len(s) - one[-1])
                for k in xrange(1, len(one)) :
                    ans += calc(one[k] - one[k - 1])
            else :
                ans += calc(len(s) + 1)
        else :
            for r in xrange(t - 1, len(one)) :
                l = r - t + 1
                x = one[l] + 1 if l == 0 else one[l] - one[l - 1]
                y = len(s) - one[r] if r + 1 == len(one) else one[r + 1] - one[r]
                ans += x * y
        return ans

