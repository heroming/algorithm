class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int x : A) {
            if (map.containsKey(x)) {
                map.put(x, map.get(x) + 1);
            } else {
                map.put(x, 1);
            }
        }
        for (int i = 0; i < B.length; ++i) {
            Map.Entry<Integer, Integer> entry = map.higherEntry(B[i]);
            if (entry == null) {
                entry = map.firstEntry();
            }

            A[i] = entry.getKey();
            if (entry.getValue() == 1) {
                map.remove(entry.getKey());
            } else {
                map.put(entry.getKey(), entry.getValue() - 1);
            }
        }

        return A;
    }
}
