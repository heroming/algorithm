class Solution(object) :
    def isValid(self, s) :
        run = True
        while run :
            run = False
            i = 0
            while i + 2 < len(s) :
                if s[i:i+3] == 'abc' :
                    run = True
                    s = s[:i] + s[i + 3:]
                i += 1
        return not s

