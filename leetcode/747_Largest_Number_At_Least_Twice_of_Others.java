package learning.leetcode;

class Solution {

    public int dominantIndex(int[] nums) {
        int a = nums[0], b = -1, idx = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (a < nums[i]) {
                b = a;
                idx = i;
                a = nums[i];
            } else if (b < nums[i]) {
                b = nums[i];
            }
        }
        return (b << 1) <= a ? idx : -1;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.dominantIndex(new int[]{3, 6, 1, 0}));
        println(so.dominantIndex(new int[]{3, 2, 1, 4}));
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
