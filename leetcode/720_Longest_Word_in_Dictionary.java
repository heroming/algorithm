class Solution {
    public String longestWord(String[] words) {

        Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                int n1 = o1.length();
                int n2 = o2.length();
                if (n1 == n2) return o1.compareTo(o2);
                return n1 < n2 ? -1 : 1;
            }
        });

        int n = words.length;
        int[] dp = new int[n];
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            map.put(words[i], i);
        }

        for (int i = 0; i < n; ++i) {
            String s = words[i].substring(0, words[i].length() - 1);
            Integer k = map.get(s);
            if (k != null) {
                if (dp[k] != 0) {
                    dp[i] = dp[k] + 1;
                }
            } else {
                if (words[i].length() == 1) {
                    dp[i] = 1;
                }
            }
        }

        int count = 0;
        String ans = "";
        for (int i = 0; i < n; ++i) {
            if (count < dp[i]) {
                count = dp[i];
                ans = words[i];
            } else if (count == dp[i]) {
                if (words[i].compareTo(ans) < 0) {
                    ans = words[i];
                }
            }
        }

        return ans;
    }
}
