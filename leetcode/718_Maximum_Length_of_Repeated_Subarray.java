package learning.leetcode;

class Solution {

    private final static int maxm = 110;
    private final static int maxn = 2010;

    private static int[] a = new int[maxn];
    private static int[] b = new int[maxn];
    private static int[] x = new int[maxn];
    private static int[] y = new int[maxn];

    private static int[] sa = new int[maxn];
    private static int[] tsa = new int[maxn];
    private static int[] ranking = new int[maxn];
    private static int[] height = new int[maxn];

    public int findLength(int[] A, int[] B) {
        final int n = A.length + B.length + 1;
        int[] s = new int[n + 3];
        int idx = 0;
        for (int x : A) s[++idx] = x;
        final int split = ++idx;
        s[split] = 101;
        for (int x : B) s[++idx] = x;
        s[++idx] = 102;
        suffixArray(s, n);

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (ans < height[i] && ((sa[i - 1] < split && sa[i] > split) || (sa[i - 1] > split && sa[i] < split))) {
                ans = height[i];
            }
        }
        return ans;
    }

    private void suffixArray(int[] s, int n) {
        for (int i = 0; i < maxm; ++i) a[i] = 0;
        for (int i = 1; i <= n; ++i) ++a[s[i]];
        for (int i = 1; i < maxm; ++i) a[i] += a[i - 1];
        for (int i = n; i >= 1; --i) sa[a[s[i]]--] = i;
        ranking[sa[1]] = 1;
        for (int i = 2; i <= n; ++i) {
            ranking[sa[i]] = ranking[sa[i - 1]];
            if (s[sa[i]] != s[sa[i - 1]]) ++ranking[sa[i]];
        }
        for (int l = 1; ranking[sa[n]] < n; l <<= 1) {
            for (int i = 0; i <= n; ++i) a[i] = b[i] = 0;
            for (int i = 1; i <= n; ++i) {
                ++a[x[i] = ranking[i]];
                ++b[y[i] = (i + l <= n ? ranking[i + l] : 0)];
            }
            for (int i = 1; i <= n; ++i) {
                a[i] += a[i - 1];
                b[i] += b[i - 1];
            }
            for (int i = n; i >= 1; --i) tsa[b[y[i]]--] = i;
            for (int i = n; i >= 1; --i) sa[a[x[tsa[i]]]--] = tsa[i];
            ranking[sa[1]] = 1;
            for (int i = 2; i <= n; ++i) {
                ranking[sa[i]] = ranking[sa[i - 1]];
                if (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]) ++ranking[sa[i]];
            }
        }
        for (int i = 1, j = 0; i <= n; ++i) {
            if (j > 0) --j;
            while (s[i + j] == s[sa[ranking[i] - 1] + j]) ++j;
            height[ranking[i]] = j;
        }
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.findLength(new int[]{1, 2, 3, 2, 1}, new int[]{3, 2, 1, 4, 7}));
        println(so.findLength(new int[]{1,2,3,2,1,3,4,5,6,7}, new int[]{3,2,1,4,3,4,5,6,7}));
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
