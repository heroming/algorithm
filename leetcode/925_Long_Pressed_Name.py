
class Solution(object) :
    def isLongPressedName(self, a, b) :
        def solve(s) :
            v = []
            p, n = None, 0
            for c in s :
                if p is None :
                    p, n = c, 1
                elif c == p :
                    n += 1
                else :
                    v.append((p, n))
                    p, n = c, 1
            v.append((p, n))

            return v

        x, y = solve(a), solve(b)
        if len(x) != len(y) :
            return False
        for i in xrange(len(x)) :
            if x[i][0] != y[i][0] :
                return False
            if x[i][1] > y[i][1] :
                return False
        return True

