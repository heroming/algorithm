class Solution {
    public int consecutiveNumbersSum(int N) {
        final int n = (int) Math.sqrt(N * 2.0);
        int ans = 0;
        for (int i = 1; i <= n; i += 2) {
            if (N % i == 0) {
                ++ans;
            }
        }

        for (int i = 1; (i << 1) <= n; ++i) {
            if (N % i == 0 && (N / i & 1) == 1) {
                ++ans;
            }
        }
        return ans;
    }
}
