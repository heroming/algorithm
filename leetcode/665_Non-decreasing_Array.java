/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
    public boolean checkPossibility(int[] v) {
        final int n = v.length;
        int count = 0;
        int index = -1;
        for (int i = 1; i < n; ++ i) {
            if (v[i - 1] > v[i]) {
                index = i - 1;
                if (++ count > 1) return false;
            }
        }
        if (index <= 0 || index + 2 == n) return true;
        return v[index - 1] <= v[index + 1] || v[index] <= v[index + 2];
    }

    public static void main(String[] args) {
        Solution so = new Solution();

        int[] v = {4, 2, 3};
        System.out.println(so.checkPossibility(v));
        v = new int[]{4, 2, 1};
        System.out.println(so.checkPossibility(v));
    }
}
