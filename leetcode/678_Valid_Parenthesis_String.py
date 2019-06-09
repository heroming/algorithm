class Solution(object) :
    def checkValidString(self, s) :

        def rebuild(s, l, r, e) :
            k, v = 0, []
            for c in s :
                if c != '*' :
                    v.append(c)
                    continue
                if k < l :
                    v.append('(')
                elif k >= l + e :
                    v.append(')')
                k += 1
            return ''.join(v)

        def valid(s) :
            n = 0
            for c in s :
                if c == '(' :
                    n += 1
                else :
                    if n == 0 :
                        return False
                    n -= 1
            return n == 0

        l, r, e = 0, 0, 0
        for c in s :
            if c == '(' :
                l += 1
            elif c == ')' :
                r += 1
            else :
                e += 1
        if abs(l - r) > e :
            return False

        t = None
        if l < r :
            x = e - (r - l)
            t = rebuild(s, r - l + (x >> 1), x >> 1, x & 1)
        else :
            x = e - (l - r)
            t = rebuild(s, x >> 1, l - r + (x >> 1), x & 1)

        return valid(t)

