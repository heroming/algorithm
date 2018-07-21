class Solution {
    public int compress(char[] chars) {
        char c = chars[0];
        int idx = 0, count = 1;
        for (int i = 1; i < chars.length; ++i) {
            if (chars[i] == c) {
                ++count;
            } else {
                idx = solve(chars, c, idx, count);
                c = chars[i];
                count = 1;
            }
        }
        return solve(chars, c, idx, count);
    }

    private int solve(char[] chars, char c, int id, int n) {
        chars[id++] = c;
        if (n > 1) {
            char[] v = String.valueOf(n).toCharArray();
            for (char x : v) {
                chars[id++] = x;
            }
        }
        return id;
    }
}
