package learning.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {

    public String[] findWords(String[] words) {
        String[] s = new String[]{"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length; ++ i) {
            for (char c : s[i].toCharArray()) {
                map.put(c, i);
            }
        }
        ArrayList<String> ret = new ArrayList<>();
        for (String word : words) {
            if (valid(word.toUpperCase(), map)) {
                ret.add(word);
            }
        }
        return ret.toArray(new String[0]);
    }

    private boolean valid(String s, Map<Character, Integer> map) {
        int id = map.get(s.charAt(0));
        for (char c : s.toCharArray()) {
            if (map.get(c) != id) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        println(so.findWords(new String[]{"Hello", "Alaska", "Dad", "Peace"}));
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

    public static <T> void println(T[] v) {
        System.out.print("[");
        for (T x : v) {
            System.out.print(" " + x);
        }
        System.out.println("]");
    }

}
