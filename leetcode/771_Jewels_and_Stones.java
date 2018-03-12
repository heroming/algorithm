package learning.leetcode;

import java.util.HashSet;
import java.util.Set;

class Solution {

    public int numJewelsInStones(String J, String S) {
        Set<Character> set = new HashSet<>();
        for (char c : J.toCharArray()) {
            set.add(c);
        }
        int count = 0;
        for (char c : S.toCharArray()) {
           if (set.contains(c)) {
               ++count;
           }
        }
        return count;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.numJewelsInStones("aA", "aAAbbbb"));
        println(so.numJewelsInStones("z", "ZZ"));
    }

    public static void println(boolean x) {
        System.out.println(x);
    }

    public static void println(String x) {
        System.out.println(x);
    }

    public static void println(int x) {
        System.out.println(x);
    }

    public static void println(int[] v) {
        System.out.print("[");
        for (int x : v) {
            System.out.print(" " + x);
        }
        System.out.println("]");
    }

}
