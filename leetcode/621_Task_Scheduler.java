package learning.leetcode;

import java.util.Arrays;

class Solution {

    public int leastInterval(char[] tasks, int n) {
        if (n == 0) return tasks.length;

        final int N = 32;
        int[] count = new int[N];
        for (char c : tasks) {
            ++count[c - 'A'];
        }
        Arrays.sort(count);
        int k = N - 2, top = 1, m = count[N - 1];
        while (count[k--] == m) ++top;
        if (top <= n + 1) {
            int s = (m - 1) * (n + 1) + top;
            int x = m * top;
            int y = tasks.length - x;
            if (x + y < s) {
                return s;
            }
        }
        return tasks.length;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.leastInterval(new char[]{'B', 'A', 'A', 'B', 'B', 'A'}, 2));
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
