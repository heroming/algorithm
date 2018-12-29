class Solution {

    public int maxChunksToSorted(int[] s) {
        int n = s.length;
        int[] p = new int[n];

        for (int i = 0; i < n; ++i) {
            p[i] = Math.max(i, s[i]);
        }

        int ans = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            if (end < p[i]) {
                end = p[i];
            }
            if (i == end) {
                ++ans;
            }
        }

        return ans;
    }
}
