package learning.leetcode;


import java.util.Arrays;

class Solution {

    private int solve(int[] v, int w) {
        int ret = 0;
        int l = 0, r = 0;
        for (int i = 0; i < v.length; ++i) {
            while (w < v[i] - v[l]) ++l;
            while (r < v.length && v[r] - v[i] <= w) ++r;
            ret += r - l - 1;
        }
        return ret >> 1;
    }

    public int smallestDistancePair(int[] v, int k) {
        Arrays.sort(v);
        int l = 0, r = v[v.length - 1] - v[0];
        while (l <= r) {
            int m = (l + r) >> 1;
            if (solve(v, m) < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        int[] v = new int[]{1, 3, 1};
        println(so.smallestDistancePair(v, 3));
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
