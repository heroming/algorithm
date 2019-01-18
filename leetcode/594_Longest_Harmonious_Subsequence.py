class Solution(object) :
    def findLHS(self, s) :
        dic = {}
        for x in s :
            if x in dic :
                dic[x] += 1
            else :
                dic[x] = 1
        ans = 0
        for x in dic.keys() :
            if x + 1 in dic :
                ans = max(ans, dic[x] + dic[x + 1])
        return ans

