class Solution(object) :
    def numTilePossibilities(self, tiles) :

        def dfs(x) :
            if x :
                self.dic[x] = True
            if len(x) == self.n :
                return
            for i in xrange(self.n) :
                if self.use[i] :
                    self.use[i] = False
                    dfs(x + self.s[i])
                    self.use[i] = True

        self.s = tiles
        self.n = len(tiles)
        self.use = [True for i in xrange(self.n)]
        self.dic = {}
        dfs("")
        return len(self.dic)

