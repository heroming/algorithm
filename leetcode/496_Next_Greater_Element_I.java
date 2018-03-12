package learning.leetcode;

import java.util.HashMap;
import java.util.Stack;

class Solution {

    public int[] nextGreaterElement(int[] a, int[] b) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < a.length; ++i) {
            map.put(a[i], i);
        }
        Stack<Integer> stack = new Stack<Integer>();
        int idx = b.length - 1;
        while (idx >= 0) {
            int x = b[idx--];
            while (!stack.empty() && stack.lastElement() < x) stack.pop();
            if (map.containsKey(x)) {
                a[map.get(x)] = stack.empty() ? -1 : stack.lastElement();
            }
            stack.push(x);
        }
        return a;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
    }

    public static void println(int[] v) {
        System.out.print("[");
        for (int x : v) {
            System.out.print(" " + x);
        }
        System.out.println("]");
    }

}
