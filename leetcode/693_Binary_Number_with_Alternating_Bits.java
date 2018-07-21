class Solution {
    public boolean hasAlternatingBits(int n) {
        int bit = 0, pre = -1;
        while (n > 0) {
            bit = n & 1;
            if (pre != -1 && (pre ^ bit) != 1) {
                return false;
            }
            pre = bit;
            n >>= 1;
        }
        return true;
    }
}
