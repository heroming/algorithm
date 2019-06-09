class Solution(object) :

    def __init__(self, rects) :
        self.rects = rects
        self.area = []
        self.total = 0
        for r in self.rects :
            a = (r[2] - r[0] + 1) * (r[3] - r[1] + 1)
            self.area.append(a)
        self.total = sum(self.area)
        for i in xrange(1, len(self.rects)) :
            self.area[i] += self.area[i - 1]

    def pick(self) :
        rand = random.randint(0, self.total - 1)
        idx = self.binary_search(rand)
        rec = self.rects[idx]
        x = random.randint(rec[0], rec[2])
        y = random.randint(rec[1], rec[3])
        return [x, y]

    def binary_search(self, w) :
        l, r = 0, len(self.area) - 1
        while l <= r :
            m = (l + r) >> 1
            if w < self.area[m] :
                r = m - 1  
            else :
                l = m + 1
        return l

