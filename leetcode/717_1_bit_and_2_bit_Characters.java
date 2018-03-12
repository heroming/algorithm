/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        final int n = bits.length;
        int idx = 0;
        while (idx + 1 < n) {
            if (bits[idx] == 1) {
                idx += 2;
            } else {
                idx += 1;
            }
        }
        return idx < n;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        Print(so.isOneBitCharacter(new int[]{1,0,0}));
        Print(so.isOneBitCharacter(new int[]{1,1,1,0}));
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
