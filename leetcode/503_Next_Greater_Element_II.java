/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
    public int[] nextGreaterElements(int[] v) {
        final int n = v.length;
        int[] ans = new int[n];
        if (n == 0) return ans;

        int max = v[0], idx = 0;
        for (int i = 1; i < n; ++ i) {
            if (max < v[i]) {
                idx = i;
                max = v[i];
            }
        }

        int top = -1;
        int[] stack = new int[n];

        ans[idx] = -1;
        stack[++ top] = max;
        for (int i = 1; i < n; ++ i) {
            int k = i <= idx ? idx - i : idx - i + n;
            while (top >= 0 && stack[top] <= v[k]) -- top;
            ans[k] = top == -1 ? -1 : stack[top];
            stack[++ top] = v[k];
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution so = new Solution();

        int[] v = {1, 2, 1};
        int[] ret = so.nextGreaterElements(v);
        for (int x : ret) System.out.printf(" " + x);
        System.out.println();

        v = new int[]{4, 2, 1};
        ret = so.nextGreaterElements(v);
        for (int x : ret) System.out.printf(" " + x);
        System.out.println();
    }
}
