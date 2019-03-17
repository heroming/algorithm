class Solution(object) :
    def bitwiseComplement(self, n) :
        if n == 0 :
            return 1
        ret, m = 0, 1
        while m <= n :
            ret |= (n & m) ^ m
            m <<= 1
        return ret

