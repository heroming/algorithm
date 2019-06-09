class Solution(object) :
    def smallestSubsequence(self, s) :

        def find_upper(v, bound) :
            l, r = 0, len(v) - 1
            while l <= r :
                m = (l + r) >> 1
                if v[m] <= bound :
                    l = m + 1
                else :
                    r = m - 1
            return l

        def satisfy(dic, bound) :
            for c in dic :
                if dic[c][-1] < bound :
                    return False
            return True

        def valid(dic, c, bound) :
            v = dic[c]
            p = find_upper(v, bound)
            return v[p] if p < len(v) and satisfy(dic, v[p]) else -1

        dic = {}
        for i in xrange(len(s)) :
            if s[i] in dic :
                dic[s[i]].append(i)
            else :
                dic[s[i]] = [i]

        ans, bound = [], -1
        while dic :
            for c in sorted(dic.keys()) :
                p = valid(dic, c, bound)
                if p > bound :
                    del dic[c]
                    bound = p
                    ans.append(c)
                    break

        return ''.join(ans)

