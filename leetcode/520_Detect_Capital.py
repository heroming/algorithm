class Solution(object) :
    def detectCapitalUse(self, word) :

        def isCapital(c) :
            return 'A' <= c <= 'Z'

        n = len(word)
        capital = 0
        for c in word :
            if isCapital(c) :
                capital += 1
        return capital == 0 or capital == n or (capital == 1 and isCapital(word[0]))

