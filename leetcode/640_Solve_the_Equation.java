package learning.leetcode;

class Solution {

    public String solveEquation(String equation) {
        String[] eq = equation.split("=");

        int[] left = solve(eq[0]);
        int[] right = solve(eq[1]);

        int k = left[0] - right[0];
        int w = right[1] - left[1];

        if (k == 0) {
            if (w == 0) {
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        } else {
            if (w % k == 0) {
                return String.format("x=%d", w / k);
            } else {
                return "No solution";
            }
        }
    }

    private int[] solve(String s) {
        int coe = 0, val = 0;

        int x = -1, sgn = 1;
        for (char c : s.toCharArray()) {
            if (c == '-' || c == '+') {
                val += (x == -1 ? 0 : x) * sgn;
                sgn = c == '-' ? -1 : 1;
                x = -1;
            } else if (c == 'x') {
                coe += (x == -1 ? 1 : x) * sgn;
                x = -1;
            } else {
                if (x == -1) x = 0;
                x = x * 10 + c - '0';
            }
        }
        val += (x == -1 ? 0 : x) * sgn;
        return new int[]{coe, val};
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.solveEquation("x+5-3+x=6+x-2"));
        println(so.solveEquation("x=x"));
        println(so.solveEquation("2x=x"));
        println(so.solveEquation("2x+3x-6x=x+2"));
        println(so.solveEquation("x=x+2"));
        println(so.solveEquation("0x=0"));
        println(so.solveEquation("-x=-1"));
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
