class Solution(object) :
    def canTransform(self, s, t) :
        if len(s) != len(t) :
            return False
        a, b = [], []
        for i in xrange(len(s)) :
            if s[i] in "LR" :
                a.append((s[i], i))
            if t[i] in "LR" :
                b.append((t[i], i))
        if len(a) != len(b) :
            return False
        for i in xrange(len(a)) :
            if a[i][0] != b[i][0] :
                return False
            if a[i][0] == 'L' :
                if a[i][1] < b[i][1] :
                    return False
            elif a[i][0] == 'R' :
                if a[i][1] > b[i][1] :
                    return False
        return True

