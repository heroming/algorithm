class Solution(object) :

    def rand10(self) :

        a, b = rand7(), rand7()
        while a > 5 :
            a = rand7()
        while b == 1 :
            b = rand7()
        return (a - 1) * 2 + (b & 1) + 1

