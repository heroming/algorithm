class Solution:
    def binaryGap(self, n):
        ans, last, idx = 0, 64, 0
        while n :
            if n & 1 :
                ans = max(ans, idx - last)
                last = idx
            n >>= 1
            idx += 1
        return ans

