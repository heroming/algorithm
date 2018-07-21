package learning.leetcode;

class Solution {

    private static final int N = 55;
    private static final int[] dx = {1, 0, -1, 0};
    private static final int[] dy = {0, 1, 0, -1};

    private int n, m;
    private boolean[][] vis = new boolean[N][N];

    public int[][] floodFill(int[][] image, int sr, int sc, int c) {
        if (image[sr][sc] != c) {
            n = image.length;
            m = image[0].length;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    vis[i][j] = true;
                }
            }
            dfs(image, sr, sc, c);
        }
        return image;
    }

    private void dfs(int[][] image, int x, int y, int c) {
        vis[x][y] = false;
        for (int k = 0; k < dx.length; ++k) {
            int a = x + dx[k];
            int b = y + dy[k];
            if (a >= 0 && a < n && b >= 0 && b < m && vis[a][b] && image[a][b] == image[x][y]) {
                dfs(image, a, b, c);
            }
        }
        image[x][y] = c;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        int[][] x = so.floodFill(new int[][]{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}, 1, 1, 2);
        for (int[] e : x) {
            println(e);
        }
    }

    public static void println(boolean x) {
        System.out.println(x);
    }

    public static void println(String x) {
        System.out.println(x);
    }

    public static void println(int x) {
        System.out.println(x);
    }

    public static void println(int[] v) {
        System.out.print("[");
        for (int x : v) {
            System.out.print(" " + x);
        }
        System.out.println("]");
    }

    public static <T> void println(T[] v) {
        System.out.print("[");
        for (T x : v) {
            System.out.print(" " + x);
        }
        System.out.println("]");
    }

}
