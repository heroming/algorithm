class MapSum {

    class Trie {
        private static final int CHAR = 256;
        int sum, value;
        Trie[] data;

        Trie() {
            sum = value = 0;
            data = new Trie[CHAR];
        }

        int insert(String s, int k, int x) {
            if (k == s.length()) {
                int diff = x - value;
                value = x;
                sum += diff;
                return diff;
            }
            int idx = s.charAt(k);
            if (data[idx] == null) {
                data[idx] = new Trie();
            }
            int ret = data[idx].insert(s, k + 1, x);
            sum += ret;
            return ret;
        }

        int query(String s) {
            Trie node = this;
            for (int k = 0; k < s.length(); ++ k) {
                int idx = s.charAt(k);
                if (node.data[idx] == null) return 0;
                node = node.data[idx];
            }
            return node.sum;
        }
    }

    Trie root = null;

    public MapSum() {
        root = new Trie();
    }

    public void insert(String key, int val) {
        root.insert(key, 0, val);
    }

    public int sum(String prefix) {
        return root.query(prefix);
    }
}
