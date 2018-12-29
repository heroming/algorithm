class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        int n = wall.size();
        Map<Integer, Integer> map = new HashMap<>();
        for (List<Integer> list : wall) {
            int w = 0;
            for (int x : list) {
                if (w > 0) {
                    Integer val = map.get(w);
                    if (val == null) {
                        map.put(w, n - 1);
                    } else {
                        map.put(w, val - 1);
                    }
                }
                w += x;
            }
        }

        int ans = n;
        for (int x : map.values()) {
            if (x < ans) {
                ans = x;
            }
        }

        return ans;
    }
}
