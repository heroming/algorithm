class Solution(object) :
    def checkValidString(self, s) :

        min_bucket, max_bucket = 0, 0
        for c in s :
            if c == '(' :
                min_bucket += 1
                max_bucket += 1
            elif c == ')' :
                min_bucket -= 1
                max_bucket -= 1
            else :
                min_bucket -= 1
                max_bucket += 1

            if max_bucket < 0 :
                return False
            if min_bucket == -1 :
                min_bucket = 0

        return min_bucket == 0

