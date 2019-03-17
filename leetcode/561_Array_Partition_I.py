class Solution(object) :
    def arrayPairSum(self, nums) :
        v = sorted(nums)
        ans, it, n = 0, 0, len(v)
        while it < n :
            ans += v[it]
            it += 2
        return ans

