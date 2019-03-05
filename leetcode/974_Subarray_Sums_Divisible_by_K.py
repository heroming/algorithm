class Solution(object) :
    def subarraysDivByK(self, A, K) :
        mod = [0 for x in xrange(K)]
        ans, s, mod[0] = 0, 0, 1
        for x in A :
            s = (s + x) % K
            ans += mod[s]
            mod[s] += 1 
        return ans

