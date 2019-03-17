class Solution(object) :
    def shortestToChar(self, s, c) :
        inf = 0x6688FF
        n = len(s)
        dis = [0] * n

        idx = -inf
        for i in xrange(n) :
            if s[i] == c :
                idx, dis[i] = i, 0
            else :
                dis[i] = i - idx
        idx = inf
        for i in xrange(n - 1, -1, -1) :
            if s[i] == c :
                idx = i
            else :
                dis[i] = min(dis[i], idx - i)
        return dis

