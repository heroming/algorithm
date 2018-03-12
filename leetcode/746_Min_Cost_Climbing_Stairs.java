package learning.leetcode;

class Solution {

    public int minCostClimbingStairs(int[] cost) {
        final int n = cost.length;
        int[] dp = new int[n + 2];
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n + 1; ++ i) {
            dp[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < n; ++ i) {
            dp[i + 1] = Math.min(dp[i + 1], dp[i] + cost[i]);
            dp[i + 2] = Math.min(dp[i + 2], dp[i] + cost[i]);
        }
        return dp[n];
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.minCostClimbingStairs(new int[]{10, 15, 20}));
        println(so.minCostClimbingStairs(new int[]{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}));
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
