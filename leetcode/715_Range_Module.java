class RangeModule {

    TreeSet<Range> ranges;

    public RangeModule() {
        ranges = new TreeSet<>();
    }

    public void addRange(int left, int right) {
        Iterator<Range> iter = ranges.tailSet(new Range(0, left)).iterator();
        while (iter.hasNext()) {
            Range it = iter.next();

            // bigger than this range, not overlap
            if (right < it.l) break;

            left = Math.min(left, it.l);
            right = Math.max(right, it.r);
            iter.remove();
        }
        ranges.add(new Range(left, right));
    }

    public boolean queryRange(int left, int right) {
        Range it = ranges.higher(new Range(0, left));
        return it != null && it.l <= left && it.r >= right;
    }

    public void removeRange(int left, int right) {
        Range x = null, y = null;
        Iterator<Range> iter = ranges.tailSet(new Range(0, left)).iterator();
        while (iter.hasNext()) {
            Range it = iter.next();

            // bigger than this range, not overlap
            if (right < it.l) break;

            if (it.l < left) {
                x = new Range(it.l, left);
            }

            if (it.r > right) {
                y = new Range(right, it.r);
            }

            iter.remove();
        }
        if (x != null) ranges.add(x);
        if (y != null) ranges.add(y);
    }

    class Range implements Comparable<Range> {
        int l, r;

        public Range(int l, int r) {
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Range o) {
            if (r == o.r) return l - o.l;
            return r - o.r;
        }
    }
}

