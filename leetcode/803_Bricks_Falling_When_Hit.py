class Solution(object) :
    def hitBricks(self, grid, hits) :

        def connect(x, y) :
            if x == 0 :
                return True
            for (dx, dy) in vec :
                a, b = x + dx, y + dy
                if 0 <= a < n and 0 <= b < m and grid[a][b] == 2 :
                    return True
            return False

        def dfs(x, y) :
            ret = 0
            if 0 <= x < n and 0 <= y < m and grid[x][y] == 1 :
                ret += 1
                grid[x][y] = 2
                for (dx, dy) in vec :
                    a, b = x + dx, y + dy
                    ret += dfs(a, b)
            return ret

        if not grid or not grid[0] :
            return []

        vec = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        n, m = len(grid), len(grid[0])
        ans = [0 for _ in hits]
        for (x, y) in hits :
            grid[x][y] -= 1
        for i in xrange(m) :
            dfs(0, i)
        for k in xrange(len(hits) - 1, -1, -1) :
            (x, y) = hits[k]
            grid[x][y] += 1
            if grid[x][y] == 1 and connect(x, y) :
                ans[k] = dfs(x, y) - 1

        return ans

