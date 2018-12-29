class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int n = A.length;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            while (l <= r) {
                if (A[i][l] == A[i][r]) {
                    A[i][l] ^= 1;
                    if (l < r) {
                        A[i][r] ^= 1;
                    }
                }
                ++l;
                --r;
            }
        }
        return A;
    }
}
