class Solution {
    public int scoreOfParentheses(String S) {
        int top = -1;
        int[] stack = new int[S.length()];
        for (char c : S.toCharArray()) {
            if (c == '(') {
                stack[++top] = 0;
            } else {
                int sum = 0;
                while (stack[top] != 0) {
                    sum += stack[top--];
                }
                stack[top] = sum == 0 ? 1 : (sum << 1);
            }
        }
        int ans = 0;
        while (top >= 0) {
            ans += stack[top--];
        }
        return ans;
    }
}
