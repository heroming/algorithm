package learning.leetcode;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

    private class Point {
        long x, y;

        Point(long a, long b) {
            x = a;
            y = b;
        }

        long distance(Point p) {
            return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
        }
    }

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        List<Point> v = new ArrayList<>();
        v.add(new Point(p1[0], p1[1]));
        v.add(new Point(p2[0], p2[1]));
        v.add(new Point(p3[0], p3[1]));
        v.add(new Point(p4[0], p4[1]));
        Map<Long, Integer> map = new HashMap<>();
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                long dis = v.get(i).distance(v.get(j));
                if (map.containsKey(dis)) {
                    map.put(dis, map.get(dis) + 1);
                } else {
                    map.put(dis, 1);
                }
            }
        }
        if (map.size() > 2 || map.containsKey(0L)) return false;
        long side = 0L, diagonal = 0L;
        for (Map.Entry<Long, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 2) {
                diagonal = entry.getKey();
            } else if (entry.getValue() == 4) {
                side = entry.getKey();
            }
        }
        if (side == 0 || diagonal == 0) return false;
        return diagonal == (side << 1);
    }

    public static void main(String[] args) {
        Solution so = new Solution();
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
