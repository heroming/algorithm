class Solution {

    public boolean isValid(String s) {
        if (s == null || s.isEmpty()) {
            return true;
        }
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (isStart(c)) {
                stack.push(c);
            } else {
                if (stack.isEmpty() || !isMatch(stack.pop(), c)) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    private boolean isStart(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    private boolean isMatch(char a, char b) {
        return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
    }
}
