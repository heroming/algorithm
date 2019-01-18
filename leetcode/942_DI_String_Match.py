class Solution(object):
    def diStringMatch(self, s) :
        v, n = [], len(s)
        c, x = s[0], 1
        for i in xrange(1, n + 1) :
            if i == n :
                v.append((c, x))
            elif s[i] != s[i - 1] :
                v.append((c, x))
                c, x = s[i], 1
            else :
                x += 1
        k, idx, ans = 0, 0, []
        if v[0][0] == 'D' :
            for x in xrange(v[0][1], -1, -1) :
                ans.append(x)
            k, idx = 1, v[0][1] + 1
        else :
            ans.append(0)
            idx = 1

        while k < len(v) :
            if k + 1 == len(v) :
                for i in xrange(v[k][1]) :
                    ans.append(idx + i)
            else :
                a, b = v[k][1], v[k + 1][1]
                for i in xrange(a) :
                    ans.append(idx + b + i)
                for i in xrange(b - 1, -1, -1) :
                    ans.append(idx + i)
                idx += a + b
            k += 2
        return ans

