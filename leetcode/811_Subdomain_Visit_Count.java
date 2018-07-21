class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> ans = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (String s : cpdomains) {
            String[] v = s.split(" ");
            int count = Integer.parseInt(v[0]);
            String[] u = v[1].split("\\.");

            String url = "";
            for (int i = u.length - 1; i >= 0; --i) {
                if (url.isEmpty()) {
                    url = u[i];
                } else {
                    url = u[i] + "." + url;
                }
                if (map.containsKey(url)) {
                    map.put(url, map.get(url) + count);
                } else {
                    map.put(url, count);
                }
            }
        }
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            ans.add(String.format("%d %s", entry.getValue(), entry.getKey()));
        }
        return ans;
    }
}
