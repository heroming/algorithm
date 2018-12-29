class Solution {
    final static int mod = 1000000007;
    final static int[] dx = {1, 0, -1, 0};
    final static int[] dy = {0, 1, 0, -1};

    public int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) {
            return 0;
        }
        if (N == 1) {
            int ans = 0;
            if (i == 0) ++ans;
            if (i + 1 == m) ++ans;
            if (j == 0) ++ans;
            if (j + 1 == n) ++ans;
            return ans;
        }
        int[][][] g = new int[3][m][n];
        g[0][i][j] = g[2][i][j] = 1;
        for (int k = 1; k < N; ++k) {
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (g[0][x][y] == 0) {
                        continue;
                    }
                    for (int d = 0; d < 4; ++d) {
                        int a = x + dx[d];
                        int b = y + dy[d];
                        if (a >= 0 && a < m && b >= 0 && b < n) {
                            g[1][a][b] += g[0][x][y];
                            if (g[1][a][b] >= mod) {
                                g[1][a][b] -= mod;
                            }
                        }
                    }
                }
            }
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    g[0][x][y] = g[1][x][y];
                    g[1][x][y] = 0;
                    g[2][x][y] += g[0][x][y];
                    if (g[2][x][y] >= mod) {
                        g[2][x][y] -= mod;
                    }
                }
            }
        }
        long ans = 0;
        for (int x = 0; x < m; ++x) {
            ans += g[2][x][0] + g[2][x][n - 1];
        }
        for (int y = 0; y < n; ++y) {
            ans += g[2][0][y] + g[2][m - 1][y];
        }
        return (int) (ans % mod);
    }
}
