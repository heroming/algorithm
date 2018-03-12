/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/11/02 09:58:15
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public int countBinarySubstrings(String s) {
        final int n = s.length();
        int pos = 0, idx = 0;
        ArrayList<Integer> list = new ArrayList<>();
        while (idx < n) {
            char c = s.charAt(pos);
            while (idx < n && s.charAt(idx) == c) ++ idx;
            list.add(idx - pos);
            pos = idx;
        }
        final int m = list.size();
        int ans = 0;
        for (int i = 1; i < m; ++ i) {
            ans += Math.min(list.get(i - 1), list.get(i));
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        Print(so.countBinarySubstrings("00110011"));
        Print(so.countBinarySubstrings("10101"));
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
