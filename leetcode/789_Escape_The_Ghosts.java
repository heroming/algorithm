package learning.leetcode;

class Solution {

    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int dis = distance(new int[]{0, 0}, target);
        for (int[] pos : ghosts) {
            if (distance(target, pos) <= dis) {
                return false;
            }
        }
        return true;
    }

    private int distance(int[] ori, int[] pos) {
        return Math.abs(pos[0] - ori[0]) + Math.abs(pos[1] - ori[1]);
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.escapeGhosts(new int[][]{{1, 0}, {0, 3}}, new int[]{0, 1}));
        println(so.escapeGhosts(new int[][]{{1, 0}}, new int[]{2, 0}));
        println(so.escapeGhosts(new int[][]{{2, 0}}, new int[]{1, 0}));
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
