class Solution {
    public int smallestRangeI(int[] A, int K) {
        int l = A[0], r = A[0];
        for (int x : A) {
            if (x < l) {
                l = x;
            } else if (x > r) {
                r = x;
            }
        }
        if (r - l <= (K << 1)) {
            return 0;
        }
        return r - l - (K << 1);
    }
}
