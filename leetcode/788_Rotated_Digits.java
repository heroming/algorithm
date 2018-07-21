package learning.leetcode;

class Solution {

    private static final int N = 10010;
    private static final int[] V = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
    private static int[] s = new int[N];
    private static int[] t = new int[8];

    public int rotatedDigits(int n) {
        if (n == 1) return 0;
        if (s[n] == 0) {
            s[1] = 0;
            for (int i = 2; i < N; ++ i) {
                s[i] = s[i - 1];
                if (rotate(i) != i) {
                    ++ s[i];
                }
            }
        }
        return s[n];
    }

    private int rotate(int m) {
        int k = -1, x = m;
        while (x > 0) {
            t[++k] = V[x % 10];
            if (t[k] == -1) return m;
            x /= 10;
        }
        int w = 0;
        for (int i = k; i >= 0; -- i) {
            w = w * 10 + t[i];
        }
        return w;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.rotatedDigits(10));
        println(so.rotatedDigits(1000));
        println(so.rotatedDigits(10000));
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
