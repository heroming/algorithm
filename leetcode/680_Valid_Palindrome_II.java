/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public boolean validPalindrome(String s) {
        final int n = s.length();
        boolean[] valid = new boolean[n];
        for (int l = 0, r = n - 1; l <= r;  ++ l, -- r) {
            valid[l] = valid[r] = true;
            if (s.charAt(l) != s.charAt(r)) break;
        }
        for (int k = 0; k < n; ++ k) {
            boolean ret = valid[k];
            if (ret) {
                for (int l = Math.min(k, n - 1 - k), r = Math.max(k, n - 1 - k); l < r;  ++ l, -- r) {
                    if (l == k) {
                        ++ r;
                        continue;
                    }
                    if (r == k) {
                        -- l;
                        continue;
                    }
                    if (s.charAt(l) != s.charAt(r)) {
                        ret = false;
                        break;
                    }
                }
            }
            if (ret) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        Print(so.validPalindrome("aba"));
        Print(so.validPalindrome("abbca"));
        Print(so.validPalindrome("eddce"));
        Print(so.validPalindrome("abcddcba"));
        Print(so.validPalindrome("aaaaaaaaaaaaaaaaaaaa"));
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
