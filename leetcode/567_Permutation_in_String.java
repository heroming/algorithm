/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public boolean checkInclusion(String s1, String s2) {
        final int LETTER = 26;
        int count = 0;
        int[] dic = new int[LETTER];
        for (int i = 0; i < s1.length(); ++ i) {
            ++ count;
            ++ dic[s1.charAt(i) - 'a'];
        }
        int idx = 0;
        for (int k = 0; k < s2.length(); ++ k) {
            int x = s2.charAt(k) - 'a';
            if (dic[x] == 0) {
                while (idx <= k) {
                    int z = s2.charAt(idx ++) - 'a';
                    if (z == x) break;
                    ++ count;
                    ++ dic[z];
                }
            } else {
                -- count;
                -- dic[x];
                if (count == 0) return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        Print(so.checkInclusion("ab", "cdebacd"));
        Print(so.checkInclusion("ab", "eidboaoo"));
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
