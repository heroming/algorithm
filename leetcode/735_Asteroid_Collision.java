package learning.leetcode;


import java.util.Stack;

class Solution {

    public int[] asteroidCollision(int[] v) {
        Stack<Integer> stack = new Stack<>();
        for (int x : v) {
            int last = -1;
            while (!stack.empty()) {
                last = stack.lastElement();
                if (last * x > 0 || (last < 0 && x > 0)) break;
                if (-x < last) {
                    last = 0;
                    break;
                }
                stack.pop();
                if (x == -last) {
                    last = 0;
                    break;
                }
            }
            if (last != 0) {
                stack.push(x);
            }
        }
        int ans[] = new int[stack.size()];
        int idx = 0;
        for (int x : stack) {
            ans[idx++] = x;
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.asteroidCollision(new int[]{5, 10, -5}));
        println(so.asteroidCollision(new int[]{8, -8}));
        println(so.asteroidCollision(new int[]{10, 2, -5}));
        println(so.asteroidCollision(new int[]{-2, -1, 1, 2}));
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
