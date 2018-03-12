package learning.leetcode;

class Solution {

    private int next(int n, int k, int x) {
        if (x > 0) {
            return (k + x) % n;
        } else {
            return ((k + x) % n + n) % n;
        }
    }

    public boolean circularArrayLoop(int[] s) {
        final int n = s.length;
        final int N = 0x7F7F7F7F;
        int mark = N;
        for (int k = 0; k < n; ++k) {
            if (s[k] > N) continue;
            ++mark;
            int idx = k;
            int last = 0;
            boolean negtive = false;
            while (s[idx] < N) {
                last = s[idx];
                if (last < 0) {
                    negtive = true;
                }
                s[idx] = mark;
                idx = next(n, idx, last);
            }
            if (s[idx] == mark && next(n, idx, last) != idx && !negtive) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.circularArrayLoop(new int[]{-2, 1, -1, -2, -2}));
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

}
