/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public int findLUSlength(String a, String b) {
        final int na = a.length();
        final int nb = b.length();
        if (na != nb) {
            return Math.max(na, nb);
        } else {
            return a.equals(b) ? -1 : na;
        }
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        Print(so.findLUSlength("cdebacd", "cdebacd"));
        Print(so.findLUSlength("abdfac", "eidboaoo"));
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
