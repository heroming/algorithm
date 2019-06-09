class Solution(object) :
    def sortArray(self, v) :
        def partiton(l, r) :
            k, x = l, v[r]
            for i in xrange(l, r) :
                if v[i] <= x :
                    v[i], v[k] = v[k], v[i]
                    k += 1
            v[k], v[r] = v[r], v[k]
            return k

        def quick_sort(l, r) :
            if r <= l : return
            m = partiton(l, r)
            quick_sort(l, m - 1)
            quick_sort(m + 1, r)

        random.shuffle(v)
        quick_sort(0, len(v) - 1)
        return v

