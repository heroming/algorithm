class Solution {
    class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private final static int dx[] = {1, 0, -1, 0};
    private final static int dy[] = {0, 1, 0, -1};

    private int[][] dp;
    private boolean[][] inque;
    private int[][] dis;
    private List<List<Pair>> graph;

    private int getNode(char c) {
        if (c == '@') return 0;
        if ('a' <= c && c <= 'f') return (c - 'a') << 1 | 1;
        if ('A' <= c && c <= 'F') return (c - 'A' + 1) << 1;
        return -1;
    }

    private boolean valid(int u, int v) {
        if (v == 0) return false;
        if ((v & 1) == 1) {
            return true;
        } else {
            return (u & (1 << (v - 1))) != 0;
        }
    }

    private void bfs(String[] grid, int n, int m, int px, int py, int u) {
        while (graph.size() <= u) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dis[i][j] = -1;
            }
        }
        dis[px][py] = 0;
        LinkedList<Pair> queue = new LinkedList<>();
        queue.add(new Pair(px, py));
        while (!queue.isEmpty()) {
            Pair p = queue.poll();
            for (int k = 0; k < dx.length; ++k) {
                int a = p.x + dx[k];
                int b = p.y + dy[k];
                if (a >= 0 && a < n && b >= 0 && b < m) {
                    char c = grid[a].charAt(b);
                    if (c != '#' && dis[a][b] == -1) {
                        dis[a][b] = dis[p.x][p.y] + 1;
                        if (c < 'A' || c > 'F') {
                            queue.add(new Pair(a, b));
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = getNode(grid[i].charAt(j));
                if (v > 0 && dis[i][j] > 0) {
                    graph.get(u).add(new Pair(v, dis[i][j]));
                }
            }
        }
    }

    private int solve() {
        int n = graph.size();
        dp = new int[n][1 << n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        inque = new boolean[n][1 << n];
        LinkedList<Pair> queue = new LinkedList<>();

        dp[0][0] = 0;
        inque[0][0] = true;
        queue.add(new Pair(0, 0));
        while (!queue.isEmpty()) {
            Pair p = queue.poll();
            inque[p.x][p.y] = false;

            for (Pair q : graph.get(p.x)) {
                if (valid(p.y, q.x)) {
                    int s = p.y | (1 << q.x);
                    if (dp[p.x][p.y] + q.y < dp[q.x][s]) {
                        dp[q.x][s] = dp[p.x][p.y] + q.y;
                        if (!inque[q.x][s]) {
                            inque[q.x][s] = true;
                            queue.add(new Pair(q.x, s));
                        }
                    }
                }
            }
        }

        int target = 0;
        for (int i = 1; i < n; i += 2) {
            target |= (1 << i);
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                if ((j & target) == target && dp[i][j] < ans) {
                    ans = dp[i][j];
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    public int shortestPathAllKeys(String[] grid) {
        int n = grid.length;
        int m = grid[0].length();
        dis = new int[n][m];
        graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int s = getNode(grid[i].charAt(j));
                if (s != -1) {
                    bfs(grid, n, m, i, j, s);
                }
            }
        }
        return solve();
    }
}
