class Solution(object):
    def largestTimeFromDigits(self, A) :

        def toTime() :
            if self.s[0] * 10 + self.s[1] < 24 and self.s[2] * 10 + self.s[3] < 60 :
                return "%d%d:%d%d" % (self.s[0], self.s[1], self.s[2], self.s[3])
            return ""

        def dfs(k) :
            if k == 4 :
                self.ret = max(self.ret, toTime())
                return
            for i in xrange(0, 4) :
                if self.vis[i] :
                    self.s[k] = self.data[i]
                    self.vis[i] = False
                    dfs(k + 1)
                    self.vis[i] = True

        self.ret = ""
        self.data = A
        self.vis = [True for x in A]
        self.s = [0 for x in A]

        dfs(0)
        return self.ret

