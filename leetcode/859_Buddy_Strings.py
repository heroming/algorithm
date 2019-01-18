class Solution(object):
    def buddyStrings(self, s, t) :

        if len(s) != len(t) :
            return False
        dif = []
        for i in xrange(len(s)) :
            if s[i] != t[i] :
                if len(dif) >= 2 :
                    return False
                dif.append(i)
        if len(dif) == 2 :
            a, b = dif[0], dif[1]
            return s[a] == t[b] and s[b] == t[a]
        elif len(dif) == 0 :
            dic = {}
            for c in s :
                if c in dic :
                    return True
                else :
                    dic[c] = True
            return False
        else :
            return False

