/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public int findPoisonedDuration(int[] v, int t) {
        int ans = 0;
        int last = 0;
        for (int i = 0; i < v.length; ++ i) {
            int x = v[i];
            if (last <= x) {
                ans += t;
            } else {
                ans += x + t - last;
            }
            last = x + t;
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        Print(so.findPoisonedDuration(new int[]{3,2,1}, 4));
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
