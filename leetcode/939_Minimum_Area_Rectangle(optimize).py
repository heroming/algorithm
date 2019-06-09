class Solution(object) :
    def minAreaRect(self, points) :
        n = len(points)
        nx = len(set([x for x, y in points]))
        ny = len(set([y for x, y in points]))

        if n == nx or n == ny :
            return 0

        p = {}
        if nx < ny :
            for x, y in points :
                p[x] = p.get(x, set())
                p[x].add(y)
        else :
            for x, y in points :
                p[y] = p.get(y, set())
                p[y].add(x)

        pp = {}
        for x, ys in p.iteritems() :
            if len(ys) >= 2 :
                pp[x] = ys
        p = pp

        ans = float('inf')
        for x0, ys0 in p.iteritems() :
            for x1, ys1 in p.iteritems() :
                if x0 >= x1 :
                    continue
                intersect = sorted(ys0.intersection(ys1))
                if len(intersect) < 2 :
                    continue
                dis = intersect[1] - intersect[0]
                for k in xrange(2, len(intersect)) :
                    dis = min(dis, intersect[k] - intersect[k - 1])

                ans = min(ans, dis * (x1 - x0))

        return ans if ans != float('inf') else 0

