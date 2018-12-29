class Solution {
    public int threeSumMulti(int[] A, int target) {
        int[] count = new int[301];
        for (int x : A) ++count[x];

        int n = 0;
        int[] list = new int[101];
        for (int i = 0; i <= 100; ++i) {
            if (count[i] > 0) {
                list[n++] = i;
            }
        }

        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = list[i];
            long na = count[list[i]];
            if (a * 3 == target && na >= 3) {
                ans += na * (na - 1) * (na - 2) / 6;
            }
            for (int j = i + 1; j < n; ++j) {
                int b = list[j];
                long nb = count[list[j]];

                if (a + a + b == target) {
                    ans += nb * na * (na - 1) / 2;
                } else if (a + b + b == target) {
                    ans += na * nb * (nb - 1) / 2;
                } else {

                    int c = target - a - b;
                    if (b < c) {
                        long nc = count[target - a - b];
                        ans += na * nb * nc;
                    }
                }
            }
        }

        return (int) (ans % 1000000007L);
    }
}
