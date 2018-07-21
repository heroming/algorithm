class Solution {
    public String reorganizeString(String S) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : S.toCharArray()) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        }
        char c = 'a';
        int max = 0;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (max < entry.getValue()) {
                c = entry.getKey();
                max = entry.getValue();
            }
        }
        map.remove(c);
        if ((max << 1) <= S.length() + 1) {
            StringBuilder builder = new StringBuilder();
            while (max > 0) {
                --max;
                builder.append(c);

                boolean first = true;
                Iterator<Map.Entry<Character, Integer>> iterator = map.entrySet().iterator();
                while (iterator.hasNext()) {
                    Map.Entry<Character, Integer> it = iterator.next();
                    if (max < it.getValue() || first) {
                        first = false;
                        builder.append(it.getKey());
                        if (it.getValue() == 1) {
                            iterator.remove();
                        } else {
                            map.put(it.getKey(), it.getValue() - 1);
                        }
                    }
                }
            }
            return builder.toString();
        }
        return "";
    }
}
