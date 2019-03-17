class Solution(object) :
    def sortedSquares(self, v) :

        def binarySearch(v, w) :
            l, r = 0, len(v) - 1
            while l <= r :
                m = (l + r) >> 1
                if v[m] < w :
                    l = m + 1
                else :
                    r = m - 1
            return l

        n = len(v)
        ans = []
        r = binarySearch(v, 0)
        l = r - 1
        while r < n and v[r] == 0 :
            ans.append(0)
            r += 1
        while l >= 0 and r < n :
            if v[l] + v[r] < 0 :
                ans.append(v[r] * v[r])
                r += 1
            else :
                ans.append(v[l] * v[l])
                l -= 1
        if l < 0 :
            while r < n :
                ans.append(v[r] * v[r])
                r += 1
        else :
            while l >= 0 :
                ans.append(v[l] * v[l])
                l -= 1

        return ans

