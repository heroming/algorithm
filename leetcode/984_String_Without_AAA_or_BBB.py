class Solution(object) :
    def strWithout3a3b(self, a, b):
        ans = []
        x, y = 0, 0
        while a > 0 or b > 0 :
            if a >= b :
                if x < 2 :
                    a -= 1
                    x, y = x + 1, 0
                    ans.append('a')
                elif b > 0 :
                    b -= 1
                    x, y = 0, y + 1
                    ans.append('b')
                else :
                    return "error"
            else :
                if y < 2 :
                    b -= 1
                    x, y = 0, y + 1
                    ans.append('b')
                elif a > 0 :
                    a -= 1
                    x, y = x + 1, 0
                    ans.append('a')
                else :
                    return "error"
        return ''.join(ans)

