class Solution {
    public int repeatedStringMatch(String A, String B) {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < A.length(); ++ i) {
            if (A.charAt(i) == B.charAt(0)) {
                ans = Math.min(ans, solve(A, B, i));
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private int solve(String A, String B, int k) {
        int count = 1;
        for (char c : B.toCharArray()) {
            if (k == A.length()) {
                k = 0;
                ++ count;
            }
            if (A.charAt(k) != c) {
                return Integer.MAX_VALUE;
            }
            ++ k;
        }
        return count;
    }
}
