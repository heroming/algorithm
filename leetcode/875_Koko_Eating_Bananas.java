class Solution {
    private boolean eatAll(int[] piles, int m, int h) {
        int time = 0;
        for (int x : piles) {
            time += (x + m - 1) / m;
        }
        return time <= h;
    }

    public int minEatingSpeed(int[] piles, int H) {
        int l = 1, r = 0;
        for (int x : piles) {
            if (r < x) {
                r = x;
            }
        }
        while (l <= r) {
            int m = (l + r) >> 1;
            if (eatAll(piles, m, H)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
}
