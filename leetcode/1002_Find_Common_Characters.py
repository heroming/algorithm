class Solution(object):
    def commonChars(self, A) :

        def solve(s) :
            d = {}
            for c in s :
                if c in d :
                    d[c] += 1
                else :
                    d[c] = 1
            return d

        dic = []
        for s in A :
            dic.append(solve(s))
        ans = []
        for c in A[0] :
            if c not in ans :
                m = 1000
                for d in dic :
                    if c in d :
                        m = min(m, d[c])
                    else :
                        m = 0
                        break
                for _ in xrange(m) :
                    ans.append(c)
        return ans

