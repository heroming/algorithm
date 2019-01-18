class Solution(object):
    def letterCasePermutation(self, s) :

        def dfs(s, k, t) :
            if k == len(s) :
                ans.append(t)
            else :
                dfs(s, k + 1, t + s[k])
                if 'a' <= s[k] <= 'z' :
                    dfs(s, k + 1, t + chr(ord(s[k]) + dis))
                elif 'A' <= s[k] <= 'Z' :
                    dfs(s, k + 1, t + chr(ord(s[k]) - dis))
        ans = []
        dis = ord('A') - ord('a')
        dfs(s, 0, "")

        return ans

