class Solution {
    public int shortestPathLength(int[][] graph) {
        final int n = graph.length;
        final int m = 1 << n;

        int[][] dp = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = 0;
        }

        for (int k = 1; k < n; ++k) {
            boolean finish = false;
            while (!finish) {
                finish = true;
                for (int s = 0; s < m; ++s) {
                    if (bit_count(s) != k) {
                        continue;
                    }
                    for (int u = 0; u < n; ++u) {
                        if (dp[s][u] == Integer.MAX_VALUE) {
                            continue;
                        }
                        for (int v : graph[u]) {
                            int t = s | (1 << v);
                            if (dp[s][u] + 1 < dp[t][v]) {
                                finish = false;
                                dp[t][v] = dp[s][u] + 1;
                            }
                        }
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, dp[m - 1][i]);
        }
        return ans;
    }

    private int bit_count(int s) {
        int count = 0;
        while (s > 0) {
            count += (s & 1);
            s >>= 1;
        }
        return count;
    }
}
