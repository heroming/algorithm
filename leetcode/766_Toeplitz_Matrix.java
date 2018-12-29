class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        for (int i = 0; i < n; ++i) {
            int x = i + 1, y = 1, w = matrix[i][0];
            while (x < n && y < m) {
                if (matrix[x++][y++] != w) {
                    return false;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            int x = 1, y = i + 1, w = matrix[0][i];
            while (x < n && y < m) {
                if (matrix[x++][y++] != w) {
                    return false;
                }
            }
        }
        return true;
    }
}
