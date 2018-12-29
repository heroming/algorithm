class Solution {
    public int maxDistToClosest(int[] seats) {
        final int n = seats.length;
        int[] dis = new int[n];
        int zero = 10001000;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                zero = 0;
            } else {
                dis[i] = ++zero;
            }
        }
        zero = 10001000;
        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                zero = 0;
            } else {
                dis[i] = Math.min(dis[i], ++zero);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++ i) {
            ans = Math.max(ans, dis[i]);
        }
        return ans;
    }
}
