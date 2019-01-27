class Solution(object) :
    def powerfulIntegers(self, x, y, n) :
        a, b = [1], [1]
        if x > 1 :
            while a[-1] < n :
                a.append(a[-1] * x)
            a.pop()
        if y > 1 :
            while b[-1] < n :
                b.append(b[-1] * y)
            b.pop()

        ans = []
        for u in a :
            for v in b :
                if u + v <= n :
                    ans.append(u + v)
        return list(set(ans))

