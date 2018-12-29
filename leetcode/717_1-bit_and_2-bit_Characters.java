class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length;
        boolean[] start = new boolean[n + 2];
        start[0] = true;
        for (int i = 0; i < n; ++i) {
            if (start[i]) {
                if (bits[i] == 0) {
                    start[i + 1] = true;
                } else {
                    start[i + 2] = true;
                }
            }
        }
        return start[n - 1];
    }
}
