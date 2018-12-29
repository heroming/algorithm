class Solution {
    public String toGoatLatin(String S) {
        Set<Character> set = new HashSet<Character>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        set.add('A');
        set.add('E');
        set.add('I');
        set.add('O');
        set.add('U');
        int index = 0;
        StringBuilder builder = new StringBuilder();

        for (String s : S.split(" ")) {
            if (index++ > 0) {
                builder.append(" ");
            }
            if (set.contains(s.charAt(0))) {
                builder.append(s);
                builder.append("ma");
            } else {
                builder.append(s.substring(1));
                builder.append(s.charAt(0));
                builder.append("ma");
            }
            for (int i = 0; i < index; ++i) {
                builder.append("a");
            }
        }

        return builder.toString();
    }
}
