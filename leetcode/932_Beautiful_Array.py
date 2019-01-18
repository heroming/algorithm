class Solution(object):
    def beautifulArray(self, n) :

        def dfs(s) :
            if len(s) <= 2 :
                return s
            return dfs(s[::2]) + dfs(s[1::2])

        s = [i + 1 for i in xrange(n)]
        return dfs(s)

