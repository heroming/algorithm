class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n = mat.length;
        if (n == 0) return new int[0];
        int m = mat[0].length;
        if (m == 0) return new int[0];

        int idx = 0;
        int[] ans = new int[n * m];

        for (int k = 0; k < n + m - 1; ++k) {
            if ((k & 1) == 0) {
                for (int i = n - 1; i >= 0; --i) {
                    int j = k - i;
                    if (j >= 0 && j < m) {
                        ans[idx++] = mat[i][j];
                    }
                }
            } else {
                for (int i = 0; i < n; ++i) {
                    int j = k - i;
                    if (j >= 0 && j < m) {
                        ans[idx++] = mat[i][j];
                    }
                }
            }
        }
        return ans;
    }
}
