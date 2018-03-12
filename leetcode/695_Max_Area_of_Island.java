/*
 * Author:heroming
 * File:Solution.java
 * Time:2017/11/03 10:16:16
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    private int count = 0;
    private int[] dx = {1, 0, -1, 0};
    private int[] dy = {0, 1, 0, -1};

    private boolean valid(int x, int y, int[][] grid) {
        return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && grid[x][y] == 1;
    }

    private void dfs(int x, int y, int[][] grid) {
        ++ count;
        grid[x][y] = 0;
        for (int k = 0; k < dx.length; ++ k) {
            int a = x + dx[k];
            int b = y + dy[k];
            if (valid(a, b, grid)) {
                dfs(a, b, grid);
            }
        }
    }

    public int maxAreaOfIsland(int[][] grid) {
        int ans = 0;
        for (int i = 0; i < grid.length; ++ i) {
            for (int j = 0; j < grid[i].length; ++ j) {
                if (grid[i][j] == 1) {
                    count = 0;
                    dfs(i, j, grid);
                    ans = Math.max(ans, count);
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution so = new Solution();
    }

    public static void Print(Object ob) {
        System.out.println(ob.toString());
    }
}
