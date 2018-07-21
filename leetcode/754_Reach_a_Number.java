class Solution {
    
    public int reachNumber(int n) {
        n = n > 0 ? n : -n;
        int ret = 0;
        while (n > 0) {
            n -= ++ ret;
        }
        return (n & 1) == 0 ? ret : ret + 1 + ret % 2;
    }
}
