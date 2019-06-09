class Solution(object) :
    def findOcurrences(self, text, first, second) :
        v = []
        s = text.split()
        for i in xrange(len(s) - 2) :
            if s[i] == first and s[i + 1] == second :
                v.append(s[i + 2])
        return v

