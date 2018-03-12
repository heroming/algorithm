package learning.leetcode;

class Solution {

    public int find(int n, int m, int x) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (x < i) break;
            if (x < (i << 1)) {
                count += Math.min(n, x) - i + 1;
                break;
            }
            count += Math.min(x / i, m);
        }
        return count;
    }

    public int findKthNumber(int n, int m, int k) {
        if (m < n) {
            int a = n;
            n = m;
            m = a;
        }
        int l = 1;
        int r = (k / m + 1) * m;
        while (l <= r) {
            int mi = (l + r) >> 1;
            if (find(n, m, mi) < k) {
                l = mi + 1;
            } else {
                r = mi - 1;
            }
        }
        return l;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        System.out.println(so.findKthNumber(10,2,5));
        System.out.println(so.findKthNumber(3,3,5));
        System.out.println(so.findKthNumber(2,3,6));
    }

    public static void println(int[] v) {
        System.out.print("[");
        for (int x : v) {
            System.out.print(" " + x);
        }
        System.out.println("]");
    }

}
