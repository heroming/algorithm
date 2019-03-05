class Solution(object) :
    def longestOnes(self, A, K) :
        n = len(A)
        s, e, k = 0, 0, 0
        while e < n and k <= K :
            if A[e] == 0 :
                if k < K :
                    k += 1
                else :
                    break
            e += 1
        ans = e - s

        while e < n :
            while s < n and k == K :
                if A[s] == 0 :
                    k -= 1
                s += 1
            while e < n and k <= K :
                if A[e] == 0 :
                    if k < K :
                        k += 1
                    else :
                        break
                e += 1
            ans = max(ans, e - s)

        return ans

