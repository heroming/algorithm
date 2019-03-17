class Solution(object) :
    def shipWithinDays(self, weights, D) :

        def valid(m) :
            day, w = 1, 0
            for x in weights :
                if w + x > m :
                    day, w = day + 1, x
                else :
                    w += x
            return day <= D

        l, r = max(weights), sum(weights)
        while l <= r :
            m = (l + r) >> 1
            if valid(m) :
                r = m - 1
            else :
                l = m + 1
        return l

