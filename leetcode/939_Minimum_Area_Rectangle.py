class Solution(object) :
    def minAreaRect(self, points) :

        points.sort()
        xdic, ydic = {}, {}
        se = set([(po[0], po[1]) for po in points])

        for po in points :
            if po[0] in xdic :
                xdic[po[0]].append(po[1])
            else :
                xdic[po[0]] = [po[1]]

        points.sort(key=lambda k : (k[1], k[0]))
        for po in points :
            if po[1] in ydic :
                ydic[po[1]].append(po[0])
            else :
                ydic[po[1]] = [po[0]]

        ans = 0
        xs = sorted(xdic.keys())
        for k in xrange(len(xs)) :
            u = xdic[xs[k]]
            for i in xrange(len(u)) :
                for j in xrange(i + 1, len(u)) :
                    v = ydic[u[i]]
                    for x in v :
                        if x > xs[k] and (x, u[i]) in se and (x, u[j]) in se :
                            if ans == 0 :
                                ans = (x - xs[k]) * (u[j] - u[i])
                            else :
                                ans = min(ans, (x - xs[k]) * (u[j] - u[i]))
        return ans

