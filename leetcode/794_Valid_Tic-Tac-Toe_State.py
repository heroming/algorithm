class Solution(object):
    def validTicTacToe(self, g) :
        x, o, empty = 0, 0, 0
        for s in g :
            for c in s :
                if c == 'X' :
                    x += 1
                elif c == 'O' :
                    o += 1
                else :
                    empty += 1
        if x > o + 1 or x < o :
            return False

        pa, pb = 0, 0
        a = [[0, 0, 0] for _ in range(3)]
        b = [[0, 0, 0] for _ in range(3)]

        lines = [
                [(0, 0), (0, 1), (0, 2)],
                [(1, 0), (1, 1), (1, 2)],
                [(2, 0), (2, 1), (2, 2)],
                [(0, 0), (1, 0), (2, 0)],
                [(0, 1), (1, 1), (2, 1)],
                [(0, 2), (1, 2), (2, 2)],
                [(0, 0), (1, 1), (2, 2)],
                [(0, 2), (1, 1), (2, 0)]
        ]

        for l in lines :
            (a0, b0), (a1, b1), (a2, b2) = l[0], l[1], l[2]
            if g[a0][b0] == g[a1][b1] and g[a0][b0] ==  g[a2][b2] :
                if g[a0][b0] == 'X' :
                    pa += 1
                    a[a0][b0] += 1
                    a[a1][b1] += 1
                    a[a2][b2] += 1
                elif g[a0][b0] == 'O' :
                    pb += 1
                    b[a0][b0] += 1
                    b[a1][b1] += 1
                    b[a2][b2] += 1

        if pa > 0 and pb > 0 :
            return False
        if pa > 0 and x == o :
            return False
        if pb > 0 and x > o :
            return False

        e = a if pa > 0 else b
        cnt = 0
        for l in e :
            for c in l :
                if c > 1 :
                    cnt += 1

        return cnt <= 1

