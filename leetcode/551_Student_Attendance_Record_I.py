class Solution(object) :
    def checkRecord(self, s) :
        absent, late = 0, 0
        for c in s :
            if c == 'A' :
                late = 0
                absent += 1
                if absent > 1 :
                    return False
            elif c == 'L' :
                late += 1
                if late > 2 :
                    return False
            else :
                late = 0
        return True

