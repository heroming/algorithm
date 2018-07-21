class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        final int n = graph.length;
        int[] deg = new int[n];
        List<List<Integer>> g = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) g.add(new ArrayList<>());
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                ++deg[u];
                g.get(v).add(u);
            }
        }

        List<Integer> ans = new ArrayList<>();

        boolean finish = false;
        while (!finish) {
            finish = true;
            for (int v = 0; v < n; ++v) {
                if (deg[v] == 0) {
                    ans.add(v);
                    deg[v] = -1;
                    for (int u : g.get(v)) {
                        --deg[u];
                    }
                    finish = false;
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
