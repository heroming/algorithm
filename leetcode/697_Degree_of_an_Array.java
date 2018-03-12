/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/11/01 09:51:46
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public static final int N = 50000;
    public static int [] count = new int[N];

    public int findShortestSubArray(int[] nums) {
        Arrays.fill(count, 0);
        for (int x : nums) ++ count[x];
        int degree = 0;
        for (int x : count) if (degree < x) degree = x;
        Arrays.fill(count, 0);
        int s = 0, e = 0, ans = N;
        while (e < nums.length) {
            if (++ count[nums[e]] == degree) {
                while (nums[s] != nums[e]) -- count[nums[s ++]];
                if (e - s + 1 < ans) ans = e - s + 1;
            }
            ++ e;
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
        Print(so.findShortestSubArray(new int[]{1, 2, 2, 3, 1}));
        Print(so.findShortestSubArray(new int[]{1,2,2,3,1,4,2}));
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
