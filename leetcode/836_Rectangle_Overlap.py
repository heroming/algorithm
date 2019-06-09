class Point(object) :

    def __init__(self, x, y) :
        self.x = x
        self.y = y

    def __add__(self, po) :
        return Point(self.x + po.x, self.y + po.y)

    def __sub__(self, po) :
        return Point(self.x - po.x, self.y - po.y)

    def __mul__(self, po) :
        return self.x * po.x + self.y * po.y

    def __xor__(self, po) :
        return self.x * po.y - self.y * po.x

    def __len__(self, po) :
        return math.sqrt(self.x * self.x + self.y * self.y)

    def __str__(self) :
        return "Point(%d, %d)" % (self.x, self.y)


class Solution(object) :
    def isRectangleOverlap(self, rec1, rec2) :

        def contain(a, b, c, d) :
            return c.x <= a.x and c.y <= a.y and b.x <= d.x and b.y <= d.y

        def inner(p, a, b) :
            return a.x < p.x < b.x and a.y < p.y < b.y

        def intersect(a, b, c, d) :
            x = ((b - a) ^ (c - a)) * ((b - a) ^ (d - a))
            y = ((d - c) ^ (a - c)) * ((d - c) ^ (b - c))
            return x < 0 and y < 0

        a = Point(rec1[0], rec1[1])
        b = Point(rec1[2], rec1[3])
        e = Point(rec1[0], rec1[3])
        f = Point(rec1[2], rec1[1])

        c = Point(rec2[0], rec2[1])
        d = Point(rec2[2], rec2[3])
        g = Point(rec2[0], rec2[3])
        h = Point(rec2[2], rec2[1])

        if contain(a, b, c, d) or contain(c, d, a, b) :
            return True
        if inner(a, c, d) or inner(b, c, d) or inner(e, c, d) or inner(f, c, d) :
            return True
        if inner(c, a, b) or inner(d, a, b) or inner(g, a, b) or inner(h, a, b) :
            return True
        if intersect(a, b, c, d) or intersect(a, b, g, h) :
            return True
        return False

