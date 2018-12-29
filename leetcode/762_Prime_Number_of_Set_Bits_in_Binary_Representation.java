class Solution {
    private void solve(int n, int[] count, List<List<Integer>> dp, boolean add) {
        StringBuilder builder = new StringBuilder();
        while (n > 0) {
            builder.append(n & 1);
            n >>>= 1;
        }
        String s = builder.reverse().toString();

        int one = 0;
        for (int k = 0; k < s.length(); ++k) {
            if (s.charAt(k) == '1') {
                List<Integer> list = dp.get(s.length() - k);
                for (int i = 0; i < list.size(); ++i) {
                    count[i + one] += add ? list.get(i) : -list.get(i);
                }
                ++one;
            }
        }
    }

    private boolean isPrime(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int countPrimeSetBits(int L, int R) {
        List<List<Integer>> dp = new ArrayList<>();
        int n = 0, m = R + 1;
        while (m > 0) {
            ++n;
            m >>>= 1;
        }

        for (int k = 0; k <= n; ++k) {
            List<Integer> list = new ArrayList<>();
            if (k == 0) {
                list.add(0);
            } else if (k == 1) {
                list.add(1);
            } else {
                list.add(1);
                List<Integer> last = dp.get(k - 1);
                for (int i = 1; i < last.size(); ++i) {
                    list.add(last.get(i - 1) + last.get(i));
                }
                list.add(1);
            }
            dp.add(list);
        }
        int[] count = new int[24];
        solve(L, count, dp, false);
        solve(R + 1, count, dp, true);

        int ans = 0;
        for (int k = 2; k < 24; ++k) {
            if (isPrime(k)) {
                ans += count[k];
            }
        }
        return ans;
    }
}
