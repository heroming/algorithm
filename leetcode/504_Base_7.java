/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/09/06 10:57:57
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public String convertToBase7(int n) {
        if (n == 0) return "0";
        StringBuilder s = new StringBuilder();
        boolean negative = false;
        if (n < 0) {
            n = -n;
            negative = true;
        }
        while (n > 0) {
            int x = n % 7;
            s.append(x);
            n /= 7;
        }
        if (negative) s.append("-");
        s.reverse();
        return s.toString();
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        System.out.println(so.convertToBase7(100));
        System.out.println(so.convertToBase7(-7));
        System.out.println(so.convertToBase7(-3923875));
    }
}
