package learning.leetcode;

class Solution {

    public boolean checkPerfectNumber(int n) {
        if (n <= 3) return false;
        int m = 1, x = 2;
        while (x * x < n) {
            if (n % x == 0) {
                m += x + n / x;
            }
            ++ x;
        }
        if (x * x == n) m += x;
        return n == m;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.checkPerfectNumber(28));
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
