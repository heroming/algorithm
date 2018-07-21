class Solution {
    public int expressiveWords(String S, String[] words) {
        List<String> u = solve(S);
        int ans = 0;
        for (String s : words) {
            List<String> v = solve(s);
            ans += valid(u, v);
        }
        return ans;
    }

    private List<String> solve(String s) {
        List<String> list = new ArrayList<>();
        int l = 0, r = 0;
        while (r <= s.length()) {
            if (r == s.length() || s.charAt(l) != s.charAt(r)) {
                list.add(s.substring(l, r));
                l = r;
            }
            ++ r;
        }
        return list;
    }

    private int valid(List<String> u, List<String> v) {
        if (u.size() != v.size()) return 0;
        final int n = u.size();
        for (int i = 0; i < n; ++ i) {
            if (u.get(i).charAt(0) != v.get(i).charAt(0)) return 0;
            int x = u.get(i).length();
            int y = v.get(i).length();
            if (x < y || (x != y && x == 2)) return 0;
        }
        return 1;
    }
}
