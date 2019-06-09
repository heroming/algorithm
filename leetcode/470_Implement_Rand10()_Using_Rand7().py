class Solution(object) :
    def rand10(self) :

        s = [rand7() for i in xrange(10)]
        while True :
            x = max(s)
            n = s.count(x)

            if n == 1 :
                for i in xrange(10) :
                    if s[i] == x :
                        return i + 1
            else :
                for i in xrange(10) :
                    if s[i] == x :
                        s[i] = rand7()
                    else :
                        s[i] = -1

