class Solution(object) :
    def isRationalEqual(self, S, T) :

        def parseDouble(s) :
            k = s.find("(")
            if k >= 0 :
                s = s[:k] + s[k + 1:-1] * 16
            return float(s)

        return parseDouble(S) == parseDouble(T)

