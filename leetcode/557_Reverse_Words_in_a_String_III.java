class Solution {
    public String reverseWords(String s) {
        String[] v = s.split(" ");
        StringBuilder builder = new StringBuilder();
        boolean start = true;
        for (String w : v) {
            if (!start) {
                builder.append(' ');
            }
            for (int i = w.length() - 1; i >= 0; --i) {
                builder.append(w.charAt(i));
            }
            start = false;
        }
        return builder.toString();
    }
}
